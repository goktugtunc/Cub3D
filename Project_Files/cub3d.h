/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:55:06 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/19 01:34:52 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
# include "mlx/mlx.h"
# define WINDOW_HEIGHT 1400
# define WINDOW_WIDTH 2560

typedef struct s_data
{
	char			**map;
	char			*nofile;
	void			*no;
	char			*sofile;
	void			*so;
	char			*wefile;
	void			*we;
	char			*eafile;
	void			*ea;
	int				*f;
	unsigned int	fcolor;
	void			*fandcimageptr;
	char			*fandcimage;
	int				*c;
	unsigned int	ccolor;
	int				charxpos;
	int				charypos;
	int				chardirection;
	void			*mlx;
	void			*mlxwin;
	int				charx;
	int				chary;
	int				charvisionangle;
}	t_data;

void			errormessage(char *message, int errornumber);
void			filecontrol(char *filename, t_data *data);
void			forcisdigit(char *rgb);
int				*convertint(char *convert);
void			maxintcontrol(int *numbers);
void			texturecontrol(char *texture);
int				isendorstart(char *line, int place);
void			mapcontroller(t_data *data);
void			othercontrol(char **map, int i, int j, int stat);
void			charactercontrol(t_data *data, char **map, int len);
char			**removespace(char **map, int newmapi);
void			getlatestmap(t_data *data, char **newmap);
void			freedoublepointer(char **db);
void			preparemlx(t_data *data);
int				ifpressesc(t_data *data);
int				ifpressfuncs(int sig, t_data *data);
void			ifpressw(t_data *data);
void			ifpressa(t_data *data);
void			ifpresss(t_data *data);
void			ifpressd(t_data *data);
void			ifpresskeyleft(t_data *data);
void			ifpresskeyright(t_data *data);
unsigned int	getcolortohex(int *oldcolor);
void			putfloorandceiling(t_data *data);

#endif
