/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:59:25 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 20:46:03 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_savecheck(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i] == save[i])
	{
		if (arg[i] == '\0' && save[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_namecheck(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != ' ' && arg[i] != '\t')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
	{
		if (i == 5 && arg[i - 5] == '.'
			|| i > 4 && arg[i - 5] == '.' && arg[i - 6] == '/')
		{
			printf("Extension error!\n");
			exit(1);
		}
		return (1);
	}
	return (0);
}

int	ft_mapcheck2(t_data *data, int i, int j)
{
	if (data->map.tab[i][j] != '1' && data->map.tab[i][j] != ' '
		&& data->map.tab[i][j] != '\t' && i != 0
			&& i != (data->map.y - 1) && j != 0)
	{
		if (data->map.tab[i][j + 1] == ' ' || data->map.tab[i][j + 1] == '\t'
			|| data->map.tab[i][j + 1] == '\0')
			ft_strerror(-21);
		else if (j != 0 && (data->map.tab[i][j - 1] == ' '
			|| data->map.tab[i][j - 1] == '\t'
			|| data->map.tab[i][j - 1] == '\0'))
			ft_strerror(-21);
		else if (i != 0 && (data->map.tab[i - 1][j] == ' '
			|| data->map.tab[i - 1][j] == '\t'
			|| data->map.tab[i - 1][j] == '\0'))
			ft_strerror(-21);
		else if (i != (data->map.y - 1) && (data->map.tab[i + 1][j] == ' '
			|| data->map.tab[i + 1][j] == '\t'
			|| data->map.tab[i + 1][j] == '\0'))
			ft_strerror(-21);
	}
	else
		return (1);
	return (0);
}

int	ft_mapcheck(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.y)
	{
		j = -1;
		while (++j < data->map.x)
		{
			if (ft_mapcheck2(data, i, j))
			{
				if (j == 0 && (data->map.tab[i][j] == '0'
					|| data->map.tab[i][j] == 'W'
					|| data->map.tab[i][j] == 'E' || data->map.tab[i][j] == 'S'
					|| data->map.tab[i][j] == 'N'))
					ft_strerror(-21);
				else if ((i == (data->map.y - 1) || i == 0)
					&& (data->map.tab[i][j] == '0' || data->map.tab[i][j] == 'W'
					|| data->map.tab[i][j] == 'E' || data->map.tab[i][j] == 'S'
					|| data->map.tab[i][j] == 'N'))
					ft_strerror(-21);
			}
		}
	}
	return (1);
}

int	ft_parcheck(t_data *data)
{
	if ((data->tex.no == NULL || data->tex.so == NULL
			|| data->tex.ea == NULL) || (data->tex.we == NULL))
		return (ft_strerror(-15));
	else if (data->tex.c == NONE || data->tex.f == NONE)
		return (ft_strerror(-16));
	else if (data->err.p == 0)
		return (ft_strerror(-17));
	else if (data->err.p > 1)
		return (ft_strerror(-18));
	else if (ft_mapcheck(data) == -1)
		return (ft_strerror(-19));
	return (1);
}
