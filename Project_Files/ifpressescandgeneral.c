/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpressescandgeneral.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:11:28 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/19 23:40:04 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	getcharvisionangle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				data->charvisionangle = 0;
			else if (data->map[i][j] == 'N')
				data->charvisionangle = 90;
			else if (data->map[i][j] == 'W')
				data->charvisionangle = 180;
			else if (data->map[i][j] == 'S')
				data->charvisionangle = 270;
			if (data->map[i][j] == 'W' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'N')
				return ;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ifpressesc(t_data *data)
{
	mlx_destroy_image(data->mlx, data->no);
	mlx_destroy_image(data->mlx, data->so);
	mlx_destroy_image(data->mlx, data->we);
	mlx_destroy_image(data->mlx, data->ea);
	mlx_destroy_window(data->mlx, data->mlxwin);
	exit(0);
	return (0);
}

int	ifpressfuncs(int sig, t_data *data)
{
	if (sig == 13)
		ifpressw(data);
	else if (sig == 0)
		ifpressa(data);
	else if (sig == 1)
		ifpresss(data);
	else if (sig == 2)
		ifpressd(data);
	else if (sig == 0x7B)
		ifpresskeyleft(data);
	else if (sig == 0x7C)
		ifpresskeyright(data);
	else if (sig == 53)
		ifpressesc(data);
	return (0);
}
