/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpresswasd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:41:50 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/09 10:46:54 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ifpressw(t_data *data)
{
	int	ipos;
	int	jpos;

	ipos = (data->charx + 4) / 64;
	jpos = (data->chary + 4) / 64;
	if (data->map[ipos][jpos] != '1')
	{
		data->chary += 4;
	}
	printf("posx = %d, posy = %d\n", data->charx, data->chary);
	// ileri gidecek
}

void	ifpressa(t_data *data)
{
	(void)data;

	// sola gidecek
}

void	ifpresss(t_data *data)
{
	(void)data;

	// geri gidecek
}

void	ifpressd(t_data *data)
{
	(void)data;

	// sağa gidecek
}
