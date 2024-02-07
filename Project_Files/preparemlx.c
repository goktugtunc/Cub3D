/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparemlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:50:00 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/07 18:10:42 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	haritakoy(t_data *data)
{
	void	*one;
	void	*zero;
	void	*character;

	int x = 64;
	one = mlx_xpm_file_to_image(data->mlx, "one.xpm", &x, &x);
	zero = mlx_xpm_file_to_image(data->mlx, "zero.xpm", &x, &x);
	character = mlx_xpm_file_to_image(data->mlx, "character.xpm", &x, &x);
	int	i = 0;
	int	j = 0;
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
	int	size;

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
}

void	preparemlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mlxwin = mlx_new_window(data->mlx,
			2560, 1400, "CUB3D -> gotunc - amonem");
	getmlxarguments(data);
	haritakoy(data);
	mlx_hook(data->mlxwin, 2, 0, ifpressfuncs, data);
	mlx_hook(data->mlxwin, 17, 0, ifpressesc, data);
	mlx_loop(data->mlx);
}
