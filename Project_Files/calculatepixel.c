/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatepixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:29:15 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/12 03:37:40 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	*converthex(int colorcode, int a)
// {
// 	char	*retval;

// 	retval = malloc(sizeof(char) * 3);
// 	retval[0] = "0123456789ABCDEF"[colorcode / 16];
// 	retval[1] = "0123456789ABCDEF"[colorcode % 16];
// 	retval[2] = '\0';
// 	return (retval);
// }

int 	converthex(int colorcode, int a)
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

void	putfloorandceiling(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			((int *)data->fandcimage)[j + (i * WINDOW_WIDTH)] = data->fcolor;
			j++;
		}
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			((int *)data->fandcimage)[j + (i * WINDOW_WIDTH)] = data->fcolor;
			j++;
		}
		i++;
	}
}

void	calculatepixel(t_data *data)
{
	(void)data;
}
