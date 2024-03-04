/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:00:31 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 21:02:40 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray(t_data *data)
{
	double	angle;
	double	dist;

	angle = ((double)data->ray.i - (data->mlx.x / 2)) * 33 / (data->mlx.x / 2);
	angle = angle * M_PI / 180;
	data->ray.x = data->pos.dirx * cos(angle) - data->pos.diry * sin(angle);
	data->ray.y = data->pos.diry * cos(angle) + data->pos.dirx * sin(angle);
	dist = hypot(data->ray.x, data->ray.y);
	data->ray.x /= dist;
	data->ray.y /= dist;
}

void	ft_dir(t_data *data)
{
	if (data->ray.x >= 0)
		data->ray.v = 1;
	else
		data->ray.v = 0;
	if (data->ray.y >= 0)
		data->ray.w = 1;
	else
		data->ray.w = 0;
}

void	ft_ver(t_data *data)
{
	double	x;
	double	y;

	x = floor(data->pos.x) + data->ray.v;
	y = data->pos.y + (x - data->pos.x) * (data->ray.y / data->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < data->map.y)
	{
		if (data->map.tab[(int)floor(y)][(int)(x - 1 + data->ray.v)] == '1')
		{
			data->hit.x = x;
			data->hit.y = y;
			data->hit.d = hypot(x - data->pos.x, y - data->pos.y);
			return ;
		}
		x += (2 * data->ray.v - 1);
		y += (2 * data->ray.v - 1) * data->ray.y / data->ray.x;
	}
	data->hit.x = data->pos.x;
	data->hit.y = data->pos.y;
	data->hit.d = 1000000000;
}

void	ft_hor(t_data *data)
{
	double	y;
	double	x;

	y = floor(data->pos.y) + data->ray.w;
	x = data->pos.x + (y - data->pos.y) * (data->ray.x / data->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < data->map.x)
	{
		if (data->map.tab[(int)(y - 1 + data->ray.w)][(int)floor(x)] == '1')
		{
			if (data->hit.d > hypot(x - data->pos.x, y - data->pos.y))
			{
				data->hit.x = x;
				data->hit.y = y;
				data->hit.d = hypot(x - data->pos.x, y - data->pos.y);
			}
			return ;
		}
		y += (2 * data->ray.w - 1);
		x += (2 * data->ray.w - 1) * data->ray.x / data->ray.y;
	}
}

void	ft_screen(t_data *data)
{
	int		bpp;
	int		sl;
	int		end;

	data->img.ptr = mlx_new_image(data->mlx.ptr, data->mlx.x, data->mlx.y);
	data->img.adr = (unsigned int *)mlx_get_data_addr
		(data->img.ptr, &bpp, &sl, &end);
	if (!(data->stk))
		data->stk = malloc(sizeof(t_stk) * data->mlx.x);
	while (data->ray.i < data->mlx.x)
	{
		ft_ray(data);
		ft_dir(data);
		ft_ver(data);
		ft_hor(data);
		ft_stock(data);
		ft_column(data, ft_size(data));
		data->ray.i++;
	}
}
