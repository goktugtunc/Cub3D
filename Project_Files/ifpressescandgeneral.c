/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpressescandgeneral.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:11:28 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/19 01:34:40 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
