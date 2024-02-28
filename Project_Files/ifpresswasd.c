/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpresswasd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:41:50 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/28 20:53:01 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ifpressw(t_data *data)
{
	int	ipos;
	int	jpos;
	int	temp;

	temp = data->charx;
	ipos = (data->charx - (4 * sin(data->charvisionangle * M_PI / 180))) / 64;
	jpos = data->chary / 64;
	printf("ipos = %d, jpos = %d\n", ipos, jpos);
	if (data->map[ipos][jpos] != '1')
	{
		data->charx -= (4 * sin(data->charvisionangle * M_PI / 180));
		printf("charx: %d, chary: %d\n", data->charx, data->chary);
	}
	ipos = temp / 64;
	jpos = (data->chary + (4 * cos(data->charvisionangle * M_PI / 180))) / 64;
	if (data->map[ipos][jpos] != '1')
	{
		data->chary += (4 * cos(data->charvisionangle * M_PI / 180));
		printf("charx: %d, chary: %d\n", data->charx, data->chary);
	}
	mlx_pixel_put(data->mlx, data->mlxwin, data->chary, data->charx, data->ccolor);
}

void	ifpressa(t_data *data)
{
	int	ipos;
	int	jpos;

	ipos = data->charx / 64;
	jpos = (data->chary - 4) / 64;
	printf("ipos = %d, jpos = %d\n", ipos, jpos);
	if (data->map[ipos][jpos] != '1')
	{
		data->chary -= 4;
		printf("charx: %d, chary: %d\n", data->charx, data->chary);
	}
}

void	ifpresss(t_data *data)
{
	int	ipos;
	int	jpos;

	ipos = (data->charx + 4) / 64;
	jpos = data->chary / 64;
	printf("ipos = %d, jpos = %d\n", ipos, jpos);
	if (data->map[ipos][jpos] != '1')
	{
		data->charx += 4;
		printf("charx: %d, chary: %d\n", data->charx, data->chary);
	}
}

void	ifpressd(t_data *data)
{
	int	ipos;
	int	jpos;

	ipos = data->charx / 64;
	jpos = (data->chary + 4) / 64;
	printf("ipos = %d, jpos = %d\n", ipos, jpos);
	if (data->map[ipos][jpos] != '1')
	{
		data->chary += 4;
		printf("charx: %d, chary: %d\n", data->charx, data->chary);
	}
}
