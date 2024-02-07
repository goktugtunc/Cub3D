/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:16:28 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/04 02:57:18 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	errormessage(char *message, int errornumber)
{
	printf("%s Error\n", message);
	exit(errornumber);
}

int	isendorstart(char *line, int place)
{
	int	j;

	j = 0;
	if (place == 0)
		return (1);
	while (line[j])
	{
		if (line[j] != ' ' && j < place)
		{
			j = place + 1;
			while (line[j])
			{
				if (line[j] && line[j] != ' ')
					return (0);
				j++;
			}
		}
		j++;
	}
	return (1);
}

void	freedoublepointer(char **db)
{
	int	i;

	i = 0;
	while (db[i])
		free(db[i++]);
	free(db);
}

int	doublepointersize(char **db)
{
	int	i;

	i = 0;
	while (db[i])
	{
		i++;
	}
	return (i);
}

char	**removespace(char **map, int newmapi)
{
	char	**newmap;
	int		flag;
	int		i;
	int		j;

	newmap = malloc(sizeof(char *) * (doublepointersize(map) + 1));
	i = -1;
	j = -1;
	while (map[++i])
	{
		flag = 0;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == '1'
				|| map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				flag = 1;
		}
		if (flag == 1)
			newmap[newmapi++] = ft_strdup(map[i]);
		j = -1;
	}
	newmap[newmapi] = NULL;
	freedoublepointer(map);
	return (newmap);
}
