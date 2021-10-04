/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:19:43 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 14:13:34 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_back(t_fdf *fdf)
{
	int	*img;
	int	i;

	ft_bzero(fdf->addr, WIDTH * HEIGHT * (fdf->bpp / 8));
	img = (int *)(fdf->addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		img[i] = BACKGROUND;
		i++;
	}
}

void	plot(t_point a, int color, t_fdf *fdf)
{
	int	i;

	if (a.x < WIDTH && a.y < HEIGHT && a.x > 0 && a.y > 0)
	{
		i = ((int)a.x * fdf->bpp / 8) + ((int)a.y * fdf->line_len);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

void	line(t_point a, t_point b, t_fdf *fdf)
{
	int			max;
	float		x_s;
	float		y_s;
	t_point		current;
	t_point		delta;

	delta.x = mod(b.x - a.x);
	delta.y = mod(b.y - a.y);
	x_s = b.x - a.x;
	y_s = b.y - a.y;
	max = find_max(mod(x_s), mod(y_s));
	x_s /= max;
	y_s /= max;
	current = a;
	while ((int)(current.x - b.x) || (int)(current.y - b.y))
	{
		plot(current, get_color(current, a, b, delta), fdf);
		current.x += x_s;
		current.y += y_s;
	}
}

void	print_map(t_map *map, t_fdf *fdf)
{
	int	i;

	i = 0;
	set_back(fdf);
	while (i < map->size)
	{
		if ((i + 1) % map->width != 0)
			line(projection(map->points[i], fdf),
				projection(map->points[i + 1], fdf), fdf);
		if (i / map->width != map->height - 1)
			line(projection(map->points[i], fdf),
				projection(map->points[i + map->width], fdf), fdf);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}
