/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatepixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:29:15 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/19 23:40:20 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	converthex(int colorcode, int a)
{
	int	ret1;
	int	ret2;

	ret1 = colorcode / 16 * pow(16, a);
	ret2 = colorcode % 16 * (pow(16, a - 1));
	return (ret1 + ret2);
}

unsigned int	getcolortohex(int *oldcolor)
{
	int				i;
	int				a;
	unsigned int	result;

	result = 0;
	i = 0;
	a = 5;
	while (i < 3)
	{
		result += converthex(oldcolor[i], a);
		i++;
		a -= 2;
	}
	return (result);
}

// void	createnewimages(t_data *data)
// {
// 	int	sizeline = WINDOW_WIDTH * 4;
// 	int	bpp = 32;
// 	data->fandcimageptr = mlx_new_image(data->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
// 	data->fandcimage = mlx_get_data_addr(data->fandcimageptr, &bpp, &sizeline, )
// }

void	calculatepixel(t_data *data)
{
	(void)data;
}
