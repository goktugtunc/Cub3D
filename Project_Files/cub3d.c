/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:59:56 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 21:10:59 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_data *data)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	data->ray = ray;
	data->hit = hit;
	ft_screen(data);
	mlx_put_image_to_window(data->mlx.ptr,
		data->mlx.winptr, data->img.ptr, 0, 0);
	free(data->img.ptr);
	free(data->img.adr);
}

int	ft_cubed(t_data *data, char *cub)
{
	data->pos.x = 0;
	data->pos.y = 0;
	data->pos.dirx = 0;
	data->pos.diry = 0;
	data->mlx.ptr = mlx_init();
	if (ft_parse(data, cub) == -1)
		return (ft_close(data, 0));
	convertwall(data);
	data->mlx.winptr = mlx_new_window(data->mlx.ptr,
			data->mlx.x, data->mlx.y, "cub3D");
	ft_draw(data);
	mlx_hook(data->mlx.winptr, 2, 0, ft_key, data);
	mlx_hook(data->mlx.winptr, 17, 0, ft_close, data);
	mlx_loop(data->mlx.ptr);
	return (1);
}

void	ft_init(char *cub)
{
	t_data	data;

	data.mlx.ptr = NULL;
	data.mlx.winptr = NULL;
	data.img.ptr = NULL;
	data.img.adr = NULL;
	data.err.m = 0;
	data.err.n = 0;
	data.err.p = 0;
	data.mlx.x = 2560;
	data.mlx.y = 1400;
	data.map.tab = NULL;
	data.tex.no = NULL;
	data.tex.so = NULL;
	data.tex.so = NULL;
	data.tex.ea = NULL;
	data.tex.we = NULL;
	data.map.x = 0;
	data.map.y = 0;
	data.tex.c = NONE;
	data.tex.f = NONE;
	data.stk = NULL;
	ft_cubed(&data, cub);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_init(av[1]);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
