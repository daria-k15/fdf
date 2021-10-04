/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:41:09 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 14:41:13 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define WIDTH			1440
# define HEIGHT			810

# define BACKGROUND		0X000000

# define UP_ARR		126
# define RIGHT_ARR	124
# define DOWN_ARR	125
# define LEFT_ARR	123

# define ESC		53

# define J_KEY		38
# define U_KEY		32
# define K_KEY		40
# define I_KEY		34
# define L_KEY		37
# define O_KEY		31

# define NUM_MINUS_KEY	78
# define NUM_PLUS_KEY	69
# define MINUS_KEY		27
# define PLUS_KEY		24
# define KEY_0			29

# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21

# define LEFT_BUTTON	1
# define RIGHT_BUTTON	2
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define LESS_BUTTON	43
# define MORE_BUTTON	47

# define LOW	0x00FFFF
# define HIGH	0xFF00FF

typedef enum s_proj
{
	TOP,
	FRONT,
	SIDE,
	ISO
}	t_proj;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}		t_point;

typedef struct s_map
{
	int		size;
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	int		i;
	t_point	*points;
}			t_map;

typedef struct s_mouse
{
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	char	pressed;
}			t_mouse;

typedef struct s_cam
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_div;
	int		x_offset;
	int		y_offset;
	t_proj	proj;
}			t_cam;

typedef struct s_fdf
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_map	*map;
	t_mouse	*mouse;
	t_cam	*cam;
}			t_fdf;

/*		create color		*/
double	percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		get_color(t_point current, t_point start, t_point end, t_point delta);

/*		color.c			*/
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);
int		rgb(int r, int g, int b);
void	set_default_color(t_map *map);

/*		key control			*/
int		button_press(int button, void *param);
int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		close_win(void *param);

/*		inits.c			*/
t_map	*map_init(char *file);
t_cam	*cam_init(t_fdf *fdf);
t_fdf	*fdf_init(t_map *map);

/*		operations.c	*/
void	move(int button, t_fdf *fdf);
void	rotate(int button, t_fdf *fdf);
void	zoom(int button, t_fdf *fdf);
void	scale(int button, t_fdf *fdf);
void	change_proj(int button, t_fdf *fdf);

/*		print.c		*/
void	set_back(t_fdf *fdf);
void	plot(t_point a, int color, t_fdf *fdf);
void	line(t_point a, t_point b, t_fdf *fdf);
void	print_map(t_map *map, t_fdf *fdf);

/*		projection.c	*/
void	iso(float *x, float *y, int z);
void	rotate_x(float *y, int *z, double alpha);
void	rotate_y(float *x, int *z, double beta);
void	rotate_z(float *x, float *y, double gamma);
t_point	projection(t_point point, t_fdf *fdf);

/*		read_file.c		*/
int		word_count(char *str, char c);
void	free_split(char **str);
int		map_size(char *file, t_map *map);
// void	get_data(char **matrix, t_map *map);
int		read_file(char *file, t_map *map);

/*		utils.c		*/
float	find_max(float x, float y);
float	mod(float a);
float	find_min(float x, float y);
int		zoom_def(t_fdf *fdf);

#endif
