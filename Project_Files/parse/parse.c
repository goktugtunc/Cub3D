/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:59:46 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 20:37:17 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	isone(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t')
			return (0);
		else if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_line(t_data *data, char *line, int i)
{
	if (line[i] != '\0' && (isone(line) || data->err.m == 1))
		data->err.n = ft_map(data, line, &i);
	else if (!ft_strncmp(line + i, "NO ", 3))
		data->err.n = ft_textures(data, &data->tex.no, line, &i);
	else if (!ft_strncmp(line + i, "SO ", 3))
		data->err.n = ft_textures(data, &data->tex.so, line, &i);
	else if (!ft_strncmp(line + i, "WE ", 3))
		data->err.n = ft_textures(data, &data->tex.we, line, &i);
	else if (!ft_strncmp(line + i, "EA ", 3))
		data->err.n = ft_textures(data, &data->tex.ea, line, &i);
	else if (!ft_strncmp(line + i, "F ", 2))
		data->err.n = ft_colors(&data->tex.f, line, &i);
	else if (!ft_strncmp(line + i, "C ", 2))
		data->err.n = ft_colors(&data->tex.c, line, &i);
	if (ft_spaceskip(line, &i) && data->err.n == 0 && line[i] != '\0')
		return (ft_strerror(-10));
	if (data->err.n < 0)
		ft_strerror(data->err.n);
	return (0);
}

int	get_next_line_extra_control(char **line,
				int read_size, char *stock, int control)
{
	if (*line == NULL)
		return (-3);
	if (read_size == 0)
	{
		if (control == 1)
			free(stock);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[4096];
	static char	*stock = NULL;

	if (line == NULL)
		return (-3);
	*line = NULL;
	read_size = 1;
	while (newline_check(stock, read_size))
	{
		read_size = read(fd, buf, 4095);
		if (read_size == -1)
			return (-3);
		buf[read_size] = '\0';
		stock = buf_join(stock, buf);
		if (stock == NULL)
			return (-3);
	}
	*line = get_line(stock);
	if (get_next_line_extra_control(line, read_size, stock, 1) != 1)
		return (get_next_line_extra_control(line, read_size, stock, 2));
	stock = stock_trim(stock);
	if (stock == NULL)
		return (-3);
	return (1);
}

int	ft_parse(t_data *data, char *cub)
{
	char		*line;
	char		*temp;
	int			fd;
	static int	ret = 1;

	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(-1));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		islineinmap(&line, &temp);
		if (ft_line(data, line, 0) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (ret == -1 || ret == -3)
		return (ft_strerror(ret + 1));
	ft_get_new_map(data);
	ft_pos(data, -1, -1);
	return (ft_parcheck(data));
}
