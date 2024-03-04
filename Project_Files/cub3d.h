/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:00:04 by gotunc            #+#    #+#             */
/*   Updated: 2024/03/04 21:11:18 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

typedef struct s_mlx
{
	void	*ptr;
	void	*winptr;
	int		x;
	int		y;
}	t_mlx;

typedef struct s_img
{
	void			*ptr;
	unsigned int	*adr;
}	t_img;

typedef struct s_err
{
	int	n;
	int	m;
	int	p;
}	t_err;

typedef struct s_map
{
	char	**tab;
	int		x;
	int		y;
}	t_map;

typedef struct s_textures
{
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*ea;
	unsigned int	*we;
	unsigned int	c;
	unsigned int	f;
}	t_textures;

typedef struct s_pos
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
}	t_pos;

typedef struct s_ray
{
	double	x;
	double	y;
	int		i;
	double	v;
	double	w;
}	t_ray;

typedef struct s_hit
{
	double			x;
	double			y;
	double			d;
}	t_hit;

typedef struct s_stk
{
	double			x;
	double			y;
	double			d;
}	t_stk;

typedef struct s_data
{
	t_mlx			mlx;
	t_img			img;
	t_err			err;
	t_map			map;
	t_textures		tex;
	t_pos			pos;
	t_ray			ray;
	t_hit			hit;
	t_stk			*stk;
}				t_data;

void			ft_init(char *cub);
int				ft_cubed(t_data *data, char *cub);
void			ft_draw(t_data *data);

int				ft_parse(t_data *data, char *cub);
int				get_next_line(int fd, char **line);
int				ft_line(t_data *data, char *line, int i);

int				ft_map(t_data *data, char *line, int *i);
char			*ft_copystr(t_data *data, char *line, int *i);
int				ft_mapstrlen(t_data *data, char *line);
int				ft_textures(t_data *data,
					unsigned int **adr, char *line, int *i);
int				ft_xpm(t_data *data, unsigned int **adr, char *file);

void			ft_pos(t_data *data, int i, int j);
int				ft_colors(unsigned int *color, char *line, int *i);

int				ft_parcheck(t_data *data);
int				ft_mapcheck(t_data *data);
int				ft_savecheck(char *arg, char *save);
int				ft_namecheck(char *arg, char *ext);

int				ft_key(int key, void *arg);
void			ft_rotate(t_data *data, double c);
void			ft_ifpressaord(t_data *data, double c);
void			ft_ifpresswors(t_data *data, double c);
int				ft_close(t_data *data, int win);

void			ft_screen(t_data *data);
void			ft_ray(t_data *data);
void			ft_dir(t_data *data);
void			ft_ver(t_data *data);
void			ft_hor(t_data *data);

void			ft_stock(t_data *data);
int				ft_size(t_data *data);
void			ft_column(t_data *data, int start);
unsigned int	ft_pixel(t_data *data, double i);

void			ft_sprite(t_data *data);
void			ft_sorder(t_data *data);
void			ft_slocate(t_data *data, double dirx, double diry, double dist);
void			ft_sdraw(t_data *data, int loc, double dist);
unsigned int	ft_spixel(t_data *data, int index, unsigned int col);

void			ft_bdraw(t_data *data);
void			ft_bfile(t_data *data, int fd);
void			ft_binfo(t_data *data, int fd);
void			ft_bdata(t_data *data, int fd);

char			*error(char *stock);
int				newline_check(char *stock, int read_size);
char			*buf_join(char *stock, char *buf);
char			*stock_trim(char *stock);
char			*get_line(char *stock);

int				ft_atoi2(char *line, int *i);
int				ft_spaceskip(char *line, int *i);
int				ft_strerror(int err);
void			ft_get_new_map(t_data *data);
void			islineinmap(char **line, char **temp);
void			convertwall(t_data *data);

#endif
