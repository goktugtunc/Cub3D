/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:59:05 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 20:40:40 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (-5);
	(*i)++;
	r = ft_atoi2(line, i);
	(*i)++;
	g = ft_atoi2(line, i);
	(*i)++;
	b = ft_atoi2(line, i);
	ft_spaceskip(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

void	ft_pos(t_data *data, int i, int j)
{
	char	c;

	while (++i < data->map.y)
	{
		while (++j < data->map.x)
		{
			c = data->map.tab[i][j];
			if ((c == 'N' || c == 'E' || c == 'S' || c == 'W') && ++data->err.p)
			{
				data->pos.y = (double)i + 0.5;
				data->pos.x = (double)j + 0.5;
				data->pos.dirx = 0;
				data->pos.diry = 0;
				if (c == 'E')
					data->pos.dirx = 1;
				else if (c == 'W')
					data->pos.dirx = -1;
				else if (c == 'S')
					data->pos.diry = 1;
				else if (c == 'N')
					data->pos.diry = -1;
			}
		}
		j = -1;
	}
}
