/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generalcontroller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:15:06 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/07 15:35:56 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	charactercontrol(t_data *data, char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				data->charx = i * 64;
				data->chary = j * 64;
				data->chardirection = map[i][j];
				if (i == 0 || i == len)
					errormessage("Wrong map!", 21);
				else if (isendorstart(map[i], j))
					errormessage("Wrong map!", 22);
				othercontrol(map, i, j, map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	getlatestmap(t_data *data, char **newmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (newmap[i])
		i++;
	freedoublepointer(data->map);
	data->map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (newmap[i])
	{
		data->map[i] = ft_strdup(newmap[i]);
		i++;
	}
	data->map[i] = NULL;
	freedoublepointer(newmap);
}
