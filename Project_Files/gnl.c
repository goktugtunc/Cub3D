/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:00:11 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 12:17:12 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*error(char *stock)
{
	free(stock);
	return (NULL);
}

int	newline_check(char *stock, int read_size)
{
	int	i;

	i = 0;
	if (stock == NULL)
		return (1);
	if (read_size == 0)
		return (0);
	while (stock[i] != '\0')
	{
		if (stock[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*buf_join(char *stock, char *buf)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (stock != NULL && stock[i] != '\0')
		i++;
	while (buf[j] != '\0')
		j++;
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (error(stock));
	i = 0;
	j = 0;
	while (stock != NULL && stock[i] != '\0')
		new[i++] = stock[j++];
	j = 0;
	while (buf[j] != '\0')
		new[i++] = buf[j++];
	new[i] = '\0';
	if (stock != NULL)
		free(stock);
	return (new);
}

char	*stock_trim(char *stock)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] != '\0')
		i++;
	trimmed = ft_substr(stock, i, ft_strlen(stock));
	free(stock);
	return (trimmed);
}

char	*get_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (error(stock));
	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
