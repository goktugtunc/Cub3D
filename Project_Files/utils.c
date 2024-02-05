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
	}
	return (1);
}
