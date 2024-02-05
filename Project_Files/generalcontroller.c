/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generalcontroller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:15:06 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/04 03:32:12 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	charactercontrol(t_data *data, char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
			{
				data->charx = i;
				data->chary = j;
				data->chardirection = map[i][j];
				if (i == 0 || i == len)
					errormessage("Wrong map!", 21);
				else if (isendorstart(map[i], j))
				othercontrol(map, i, j, map[i][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
