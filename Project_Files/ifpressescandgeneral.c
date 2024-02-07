/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpressescandgeneral.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:11:28 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/07 18:05:34 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ifpressesc(int sig, t_data *data)
{
	(void)sig;
	write(1, "1", 1);
	mlx_destroy_image(data->mlx, data->no);
	write(1, "2", 1);
	mlx_destroy_image(data->mlx, data->so);
	write(1, "3", 1);
	mlx_destroy_image(data->mlx, data->we);
	write(1, "4", 1);
	mlx_destroy_image(data->mlx, data->ea);
	write(1, "5", 1);
	mlx_destroy_window(data->mlx, data->mlxwin);
	write(1, "6", 1);
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
	else if (sig == 0x7D)
		ifpresskeydown(data);
	else if (sig == 0x7E)
		ifpresskeyup(data);
	else if (sig == 53)
		ifpressesc(sig, data);
	return (0);
}
