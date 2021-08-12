#ifndef FDF_H
# define FDF_H

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP_FILE		"Incorrect MAP_FILE"
# define ERR_MAP_READ		"Error: reading MAP_FILE"
# define ERR_MAP_INVAL		"Invalid MAP_FILE"
# define ERR_MAP_INIT		"Initialization error: MAP"
# define ERR_CAMERA_INIT	"Initialization error: MAP"
# define ERR_SPLIT			"Error: split map"
# define ERR_FDF_INIT		"Error: init fdf"

# define STR(x, y, c, s) (mlx_string_put(fdf->mlx, fdf->win, x, y, c, s))

# define GET_RED(color)		((color >> 16) & 0xFF)
# define GET_GREEN(color)	((color >> 8) & 0xFF)
# define GET_BLUE(color)	(color & 0xFF)

#include "fdf.h"
#include "libft/include/libft.h"
#include "mlx/mlx.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

// typedef enum
// {
// 	HORIZONTAL,
// 	FRONT,
// 	CROSS,
// 	ISO
// }	t_projection;

// typedef struct			s_point
// {
// 	int					x;
// 	int					y;
// 	int					z;
// 	int					color;
// }						t_point;

typedef struct			s_map
{
	int					size;
	int					width;
	int					height;
	int					z_min;
	int					z_max;
    int                 **matrix;
    int                 color;
	// t_point				*points;
}						t_map;

typedef struct			s_mouse
{
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
	char				is_pressed;
}						t_mouse;

typedef struct			s_camera
{
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divider;
	int					x_offset;
	int					y_offset;
	// t_projection		projection;
}						t_camera;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_camera			*camera;
	t_map				*map;
	t_mouse				*mouse;
}						t_fdf;

t_fdf					*fdf_init(t_map *map);
t_map *map_init(char *name);
t_camera				*camera_init(t_fdf *fdf);
void    read_file(char *name, t_map *map);
void					print_map(t_map *map, t_fdf *fdf);
// t_point					projection(t_point point, t_fdf *fdf);

#endif
