/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecontrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:19:05 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/09 10:25:43 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*findpath(char **map, char *keyword, int counter, int i)
{
	char	**path;
	char	*temp;
	int		j;

	j = -1;
	while (map[++i])
	{
		if (!ft_strncmp(map[i], keyword, ft_strlen(keyword)))
		{
			counter++;
			j = i;
		}
	}
	if (counter != 1)
		errormessage("Content error!", 5);
	path = ft_split(map[j], ' ');
	if (path[1] == NULL || path[2] != NULL)
		errormessage("Too many or less argument in source path!", 6);
	temp = ft_strdup(path[1]);
	j = -1;
	while (path[++j])
		free(path[j]);
	free(path);
	return (temp);
}

void	filecontentcontrol(t_data *data)
{
	char	*f;
	char	*c;

	data->nofile = findpath(data->map, "NO ", 0, -1);
	data->sofile = findpath(data->map, "SO ", 0, -1);
	data->wefile = findpath(data->map, "WE ", 0, -1);
	data->eafile = findpath(data->map, "EA ", 0, -1);
	f = findpath(data->map, "F", 0, -1);
	c = findpath(data->map, "C", 0, -1);
	forcisdigit(f);
	forcisdigit(c);
	data->f = convertint(f);
	data->c = convertint(c);
	maxintcontrol(data->f);
	maxintcontrol(data->c);
	texturecontrol(data->sofile);
	texturecontrol(data->nofile);
	texturecontrol(data->wefile);
	texturecontrol(data->eafile);
}

char	*getfile(char *filename)
{
	char	*temp;
	char	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	map = get_next_line(fd);
	if (map == NULL)
		errormessage("Null file!", 4);
	temp = "";
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		if (temp != NULL)
		{
			map = ft_strjoin(map, temp);
			free(temp);
		}
	}
	return (map);
}

void	othercontrol(char **map, int i, int j, int stat)
{
	if (map[i][j] == stat && map[i + 1][j] != '1'
		&& map[i + 1][j] != '0' && map[i + 1][j] != 'N'
		&& map[i + 1][j] != 'S' && map[i + 1][j] != 'W'
		&& map[i + 1][j] != 'E')
		errormessage("Wrong map!", 14);
	else if (map[i][j] == stat && map[i - 1][j] != '1'
		&& map[i - 1][j] != '0' && map[i - 1][j] != 'N'
		&& map[i - 1][j] != 'S' && map[i - 1][j] != 'W'
		&& map[i - 1][j] != 'E')
		errormessage("Wrong map!", 15);
	else if (map[i][j] == stat && map[i][j + 1] != '1'
		&& map[i][j + 1] != '0' && map[i][j + 1] != 'N'
		&& map[i][j + 1] != 'S' && map[i][j + 1] != 'W'
		&& map[i][j + 1] != 'E')
		errormessage("Wrong map!", 16);
	else if (map[i][j] == stat && map[i][j - 1] != '1'
		&& map[i][j - 1] != '0' && map[i][j - 1] != 'N'
		&& map[i][j - 1] != 'S' && map[i][j - 1] != 'W'
		&& map[i][j - 1] != 'E')
		errormessage("Wrong map!", 17);
}

void	filecontrol(char *filename, t_data *data)
{
	char	*map;

	if (open(filename, O_RDONLY) == -1)
		errormessage("File not found!", 2);
	if (ft_strlen(filename) < 5
		|| ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 3)
		|| filename[ft_strlen(filename) - 5] == '/')
		errormessage("File name error!", 3);
	map = getfile(filename);
	data->map = ft_split(map, '\n');
	filecontentcontrol(data);
	free(map);
	mapcontroller(data);
}
