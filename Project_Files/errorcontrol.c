/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcontrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:15:52 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/04 03:00:13 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forcisdigit(char *rgb)
{
	int	i;
	int	virgulecounter;

	i = 0;
	virgulecounter = 0;
	while (rgb[i])
	{
		if (rgb[i] == ',')
			virgulecounter++;
		else if (!ft_isdigit(rgb[i]))
			errormessage("Wrong number for f or c numbers!", 7);
		i++;
	}
	if (virgulecounter != 2)
		errormessage("Wrong number count!", 8);
}

int	*convertint(char *convert)
{
	char	**temp;
	int		*ret;
	int		i;

	ret = malloc(sizeof(int) * 3);
	temp = ft_split(convert, ',');
	i = 0;
	while (temp[i])
	{
		ret[i] = ft_atoi(temp[i]);	
		free(temp[i]);
		i++;
	}
	free(convert);
	return (ret);
}

void	maxintcontrol(int *numbers)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (numbers[i] < 0 || numbers[i] > 255)
			errormessage("Wrong rgb numbers!", 8);
		i++;
	}
}

void	texturecontrol(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
		errormessage("Texture file not opened!", 9);
	close(fd);
}
