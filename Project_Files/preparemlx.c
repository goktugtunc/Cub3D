/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparemlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:50:00 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/28 21:34:30 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rayat(t_data *data)
{
	float	i;
	float	j;

	i = (float)data->charx;
	j = (float)data->chary;
	printf("i = %f, j = %f\n", i, j);
	while (1)
	{
		i = (i - (2 * sin(data->charvisionangle * M_PI / 180)));
		j = (j + (2 * cos(data->charvisionangle * M_PI / 180)));
		if (data->map[(int)i / 64][(int)j / 64] != '1')
			mlx_pixel_put(data->mlx, data->mlxwin, j, i, data->fcolor);
		else
			break ;
	}
	printf("normal koordinat: x = %f, y = %f\n", i, j);
	printf("Duvar koordinat: x = %f, y = %f\n", i / 64, j / 64);
	printf("Aradaki mesafe: %f\n", data->charx / 64 - (i / 64));
}

void	haritakoy(t_data *data)
{
	void	*one;
	void	*zero;
	void	*character;
	int	x = 64;
	int	i = 0;
	int	j = 0;

	one = mlx_xpm_file_to_image(data->mlx, "wall1.xpm", &x, &x);
	zero = mlx_xpm_file_to_image(data->mlx, "wall2.xpm", &x, &x);
	character = mlx_xpm_file_to_image(data->mlx, "wall3.xpm", &x, &x);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlxwin, zero, j * 64, i * 64);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlxwin, one, j * 64, i * 64);
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'W' || data->map[i][j] == 'S')
				mlx_put_image_to_window(data->mlx, data->mlxwin, character, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	getmlxarguments(t_data *data)
{
	int		size;
	// char	*color;

	size = 64;
	if (open(data->sofile, O_RDONLY) == -1 || open(data->nofile, O_RDONLY) == -1
		|| open(data->eafile, O_RDONLY) == -1
		|| open(data->wefile, O_RDONLY) == -1)
		errormessage("Source file not found!", 20);
	if (ft_strncmp(".xpm", data->nofile + ft_strlen(data->nofile) - 4, 4)
		|| ft_strncmp(".xpm", data->sofile + ft_strlen(data->sofile) - 4, 4)
		|| ft_strncmp(".xpm", data->eafile + ft_strlen(data->eafile) - 4, 4)
		|| ft_strncmp(".xpm", data->wefile + ft_strlen(data->wefile) - 4, 4))
		errormessage("Source file extension not correct!", 21);
	data->so = mlx_xpm_file_to_image(data->mlx, data->sofile, &size, &size);
	data->no = mlx_xpm_file_to_image(data->mlx, data->nofile, &size, &size);
	data->we = mlx_xpm_file_to_image(data->mlx, data->wefile, &size, &size);
	data->ea = mlx_xpm_file_to_image(data->mlx, data->eafile, &size, &size);
	data->fcolor = getcolortohex(data->f);
	data->ccolor = getcolortohex(data->c);
}

void	preparemlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mlxwin = mlx_new_window(data->mlx,
			2560, 1400, "CUB3D -> gotunc - amonem");
	getmlxarguments(data);
	mlx_pixel_put(data->mlx, data->mlxwin, 128, 64, data->fcolor);
	mlx_pixel_put(data->mlx, data->mlxwin, 64, 64, data->ccolor);
	getcharvisionangle(data);
	// data->fandcimageptr = mlx_new_image(data->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	// data->fandcimage = mlx_get_data_addr(data->fandcimageptr, 32, 64, 1);
	// putfloorandceiling(data);
	// mlx_put_image_to_window(data->mlx, data->mlxwin, data->fandcimage, 0, 0);
	haritakoy(data);
	mlx_hook(data->mlxwin, 2, 0, ifpressfuncs, data);
	mlx_hook(data->mlxwin, 17, 0, ifpressesc, data);
	mlx_loop(data->mlx);
}
