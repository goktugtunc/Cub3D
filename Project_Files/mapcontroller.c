/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:21:54 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/04 03:34:43 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**getnewmap(t_data *data)
{
	int		i;
	int		j;
	char	**newmap;

	i = 0;
	j = 0;
	while (data->map[i])
		i++;
	newmap = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], "SO ", 3)
			&& ft_strncmp(data->map[i], "NO ", 3)
			&& ft_strncmp(data->map[i], "WE ", 3)
			&& ft_strncmp(data->map[i], "EA ", 3)
			&& ft_strncmp(data->map[i], "F ", 2)
			&& ft_strncmp(data->map[i], "C ", 2))
			newmap[j++] = ft_strdup(data->map[i]);
		i++;
	}
	newmap[j] = NULL;
	return (newmap);
}

void	directioncontrol(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (flag == 1 && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W'))
				errormessage("Too many direction letter!", 10);
			if (flag == 0 && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W'))
				flag = 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (flag == 0)
		errormessage("Direction letter too low!", 11);
}

void	lettercontrol(char **newmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (newmap[i])
	{
		while (newmap[i][j])
		{
			if (newmap[i][j] != '1' && newmap[i][j] != '0'
				&& newmap[i][j] != 'N' && newmap[i][j] != 'S'
				&& newmap[i][j] != 'E' && newmap[i][j] != 'W'
				&& newmap[i][j] != ' ')
				errormessage("Wrong letter in map file!", 9);
			j++;
		}
		j = 0;
		i++;
	}
	directioncontrol(newmap);
}

void	mapleakcontrol(char **map)
{
	int	i;
	int	j;
	int	maplen;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	maplen = i - 1;
	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((i == 0 || i == maplen) && map[i][j] == '0')
				errormessage("Wrong map!", 12);
			else if (isendorstart(map[i], j) && map[i][j] == '0')
				errormessage("Wrong map!", 13);
			othercontrol(map, i, j, '0');
			j++;
		}
		j = 0;
		i++;
	}
}

void	mapcontroller(t_data *data)
{
	char	**newmap;
	int		i;

	i = 0;
	newmap = removespace(getnewmap(data), 0);
	while (newmap[i])
		i++;
	lettercontrol(newmap);
	mapleakcontrol(newmap);
	charactercontrol(data, newmap, i - 1);
	getlatestmap(data, newmap);
}
