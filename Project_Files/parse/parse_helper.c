/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:04:56 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 20:16:57 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	convertwall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.tab[i])
	{
		while (data->map.tab[i][j])
		{
			if (data->map.tab[i][j] == ' ')
				data->map.tab[i][j] = '1';
			j++;
		}
		j = 0;
		i++;
	}
}

void	islineinmap(char **line, char **temp)
{
	int	i;
	int	status;

	i = -1;
	status = -1;
	while (line[++i])
	{
		if (*line[i] == '1' || *line[i] == '0'
			|| (*line[i] == 'E' && *line[i + 1] != 'A')
			|| (*line[i] == 'N' && *line[i + 1] != 'O')
			|| (*line[i] == 'W' && *line[i + 1] != 'E')
			|| (*line[i] == 'S' && *line[i + 1] != 'O'))
			status = 1;
		else if (*line[i] != ' ' && *line[i] != '\t')
			status = 0;
		if (status != -1)
			break ;
	}
	if (status == 1)
	{
		*temp = ft_strtrim(*line, " \t");
		free(*line);
		*line = *temp;
	}
}

char	*create_charpointer(t_data *data, int place)
{
	char	*ret;
	int		holder;
	int		i;

	i = 0;
	ret = malloc(data->map.x - ft_strlen(data->map.tab[place]) + 2);
	if (!ret)
		exit(2);
	holder = data->map.x - ft_strlen(data->map.tab[place]);
	while (i < holder)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	converttab(t_data *data)
{
	char	*temp;
	char	*temp2;
	int		i;
	int		j;

	i = -1;
	while (data->map.tab[++i])
	{
		j = -1;
		while (data->map.tab[i][++j])
		{
			if (data->map.tab[i][j] == '\t')
			{
				temp = ft_substr(data->map.tab[i], 0, j);
				temp = ft_strjoin(temp, "    ");
				temp2 = ft_substr(data->map.tab[i], j + 1,
						ft_strlen(data->map.tab[i]));
				temp = ft_strjoin(temp, temp2);
				free(data->map.tab[i]);
				free(temp2);
				data->map.tab[i] = temp;
			}
		}
	}
}

void	ft_get_new_map(t_data *data)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	converttab(data);
	while (data->map.tab[++i])
		if (ft_strlen(data->map.tab[i]) > data->map.x)
			data->map.x = ft_strlen(data->map.tab[i]);
	i = -1;
	while (data->map.tab[++i])
	{
		if (ft_strlen(data->map.tab[i]) < data->map.x)
		{
			temp = create_charpointer(data, i);
			data->map.tab[i] = ft_strjoin(data->map.tab[i], temp);
			free(temp);
		}
	}
}
