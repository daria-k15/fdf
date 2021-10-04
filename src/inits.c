/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:16:19 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 13:16:22 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_map	*map_init(char *file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_putstr("Error in map initialisation!\n");
	map->points = (t_point *)malloc(sizeof(t_point) * map_size(file, map));
	if (!map->points)
		ft_putstr("Error in map initialisation!\n");
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	return (map);
}

t_cam	*cam_init(t_fdf *fdf)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->zoom = zoom_def(fdf);
	cam->alpha = 0;
	cam->beta = 0;
	cam ->gamma = 0;
	cam->z_div = 1;
	cam->x_offset = 0;
	cam->y_offset = -30;
	cam->proj = ISO;
	return (cam);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
			&(fdf->line_len), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!(fdf->mouse))
		ft_putstr("Error in memory allocation\n");
	return (fdf);
}
