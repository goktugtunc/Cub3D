/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:30:38 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/01 14:29:30 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	newfunction(float i, float j, int x, int y)
{
	int	newi;
	int	newj;
	if (((int)i % 64) > 61)
		newi = (int)(i / 64) * 64 + 64;
	else if (((int)i % 64) < 3)
		newi = (int)(i / 64) * 64;
	if (((int)j % 64) > 61)
		newj = (int)(j / 64) * 64 + 64;
	else if (((int)j % 64) < 3)
		newj = (int)(j / 64) * 64;
	(void)y;
	(void)x;
	printf("--i = %f, j = %f\n", i, j);
	if (((int)i % 64) - ((int)j % 64) > 0 && newj == y * 64)
		return (2);
	else if (((int)i % 64) - ((int)j % 64) > 0 && newj == y * 64 + 64)
		return (4);
	return (0);
}

int	whichdirection(float i, float j, int x, int y)
{
	float	oldi;
	float	oldj;

	oldi = i;
	oldj = j;
	printf("i = %f, j = %f\n", i, j);
	if (((int)i % 64) > 61)
		i = (int)(i / 64) * 64 + 64;
	else if (((int)i % 64) < 3)
		i = (int)(i / 64) * 64;
	if (((int)j % 64) > 61)
		j = (int)(j / 64) * 64 + 64;
	else if (((int)j % 64) < 3)
		j = (int)(j / 64) * 64;
	printf("i = %f, walli = %d\n", i, x);
	printf("j = %f, wallj = %d\n", j, y);
	if (((int)i % 64 == 0 && (int)j % 64 != 0)
		|| ((int)i % 64 != 0 && (int)j % 64 == 0))
	{
		if ((int)(i) == (x * 64))
			return (1);
		else if ((int)(j) == (y * 64))
			return (2);
		else if ((int)(i) == ((x * 64) + 64))
			return (3);
		else if ((int)(j) == ((y * 64) + 64))
			return (4);
	}
	else
		return (newfunction(oldi, oldj, x, y));
	return (0);
}

void	rayfollow(t_data *data)
{
	float	i;
	float	j;
	int		charvision;

	charvision = (data->charvisionangle - 30) % 360;
	// while (charvision != ((data->charvisionangle + 32) % 360))
	// {
		i = (float)data->charx;
		j = (float)data->chary;
		// printf("%d %d\n", (int)(j / 64), (int)(i / 64));
		while (data->map[(int)i / 64][(int)j / 64] != '1')
		{
			// i = (i - (2 * sin(charvision * M_PI / 180)));
			i = (i - (2 * sin(data->charvisionangle * M_PI / 180)));
			// j = (j + (2 * cos(charvision * M_PI / 180)));
			j = (j + (2 * cos(data->charvisionangle * M_PI / 180)));
			if (data->map[(int)i / 64][(int)j / 64] != '1')
				mlx_pixel_put(data->mlx, data->mlxwin, j, i, data->fcolor);
			else
			{
				printf("i = %d , j = %d, sonuc = %d\n", (int)i / 64, (int)j / 64, whichdirection(i, j, i / 64, j / 64));
			}
				// putwall(i / 64, j / 64, whichdirection(i, j)); // 
		}
		// charvision = (charvision + 2) % 360;
	// }
}

