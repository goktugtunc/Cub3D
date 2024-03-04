/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:00:19 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 21:04:04 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_data *data, int win)
{
	int	i;

	i = 0;
	while (i < data->map.y)
		free(data->map.tab[i++]);
	free(data->map.tab);
	free(data->tex.no);
	free(data->tex.so);
	free(data->tex.ea);
	free(data->tex.we);
	if (win == 1)
		mlx_destroy_window(data->mlx.ptr, data->mlx.winptr);
	free(data->mlx.ptr);
	exit(0);
	return (1);
}

void	ft_ifpresswors(t_data *data, double c)
{
	data->pos.x += c * (data->pos.dirx * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos.y)][(int)floor(data->pos.x)] == '1')
		data->pos.x -= c * (data->pos.dirx * SPEED / 100);
	data->pos.y += c * (data->pos.diry * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos.y)][(int)floor(data->pos.x)] == '1')
		data->pos.y -= c * (data->pos.diry * SPEED / 100);
}

void	ft_ifpressaord(t_data *data, double c)
{
	data->pos.x -= c * (data->pos.diry * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos.y)][(int)floor(data->pos.x)] == '1')
		data->pos.x += c * (data->pos.diry * SPEED / 100);
	data->pos.y += c * (data->pos.dirx * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos.y)][(int)floor(data->pos.x)] == '1')
		data->pos.y -= c * (data->pos.dirx * SPEED / 100);
}

void	ft_rotate(t_data *data, double c)
{
	double	dist;

	data->pos.dirx = data->pos.dirx
		* cos(c * TURN) - data->pos.diry * sin(c * TURN);
	data->pos.diry = data->pos.diry
		* cos(c * TURN) + data->pos.dirx * sin(c * TURN);
	dist = hypot(data->pos.dirx, data->pos.diry);
	data->pos.dirx /= dist;
	data->pos.diry /= dist;
}

int	ft_key(int key, void *arg)
{
	if (key == ESC)
		ft_close(arg, 1);
	else if (key == W)
		ft_ifpresswors(arg, 1);
	else if (key == A)
		ft_ifpressaord(arg, -1);
	else if (key == S)
		ft_ifpresswors(arg, -1);
	else if (key == D)
		ft_ifpressaord(arg, 1);
	else if (key == LEFT)
		ft_rotate(arg, -1);
	else if (key == RIGHT)
		ft_rotate(arg, 1);
	ft_draw(arg);
	return (1);
}
