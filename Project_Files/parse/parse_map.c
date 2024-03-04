/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:59:35 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 18:53:30 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_xpm(t_data *data, unsigned int **adr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_namecheck(file, "xpm") == 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(data->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int	ft_textures(t_data *data, unsigned int **adr, char *line, int *i)
{
	char	*file;
	int		j;

	if (*adr != NULL)
		return (-7);
	(*i) += 2;
	ft_spaceskip(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	file = ft_substr(line, j, *i);
	if (!file)
		return (-8);
	j = ft_xpm(data, adr, file);
	free(file);
	ft_spaceskip(line, i);
	if (line[*i] != '\0')
		ft_strerror(-20);
	if (j == -1)
		return (-9);
	return (0);
}

int	ft_mapstrlen(t_data *data, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == ' ' || line[i] == '\t')
			count++;
		else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			count++;
		i++;
	}
	return (count);
}

char	*ft_copystr(t_data *data, char *line, int *i)
{
	char	*slab;
	int		j;

	slab = malloc(sizeof(char) * (ft_mapstrlen(data, line) + 1));
	if (!slab)
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'
				|| line[*i] == ' ' || line[*i] == '\t'))
			slab[j++] = line[*i];
		else
		{
			free(slab);
			return (NULL);
		}
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

int	ft_map(t_data *data, char *line, int *i)
{
	char	**tmp;
	int		j;

	data->err.m = 1;
	tmp = malloc(sizeof(char *) * (data->map.y + 2));
	if (!tmp)
		return (-11);
	j = -1;
	while (++j < data->map.y)
		tmp[j] = data->map.tab[j];
	tmp[data->map.y] = ft_copystr(data, line, i);
	if (tmp[data->map.y] == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[data->map.y + 1] = NULL;
	if (data->map.y > 0)
		free(data->map.tab);
	data->map.tab = tmp;
	data->map.y++;
	data->map.x = ft_mapstrlen(data, line);
	if (data->map.x == -1)
		return (-13);
	return (0);
}
