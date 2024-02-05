/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:55:06 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/04 03:29:29 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"

typedef struct	s_data
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	int		charx;
	int		chary;
	int		chardirection;
}	t_data;

void	errormessage(char *message, int errornumber);
void	filecontrol(char *filename, t_data *data);
void	forcisdigit(char *rgb);
int		*convertint(char *convert);
void	maxintcontrol(int *numbers);
void	texturecontrol(char *texture);
int		isendorstart(char *line, int place);
void	mapcontroller(t_data *data);
void	othercontrol(char **map, int i, int j, int stat);
void	charactercontrol(t_data *data, char **map, int len);

#endif
