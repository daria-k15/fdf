/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:20:49 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 13:34:11 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso(float *x, float *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.46373398);
	*y = -z + (prev_x + prev_y) * sin(0.46373398);
}

void	rotate_x(float *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) - *z * sin(beta);
	*z = prev_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) + prev_y * sin(gamma);
	*y = -prev_x * sin(gamma) + prev_y * cos(gamma);
}

t_point	projection(t_point point, t_fdf *fdf)
{
	point.x *= fdf->cam->zoom;
	point.y *= fdf->cam->zoom;
	point.z *= fdf->cam->zoom / fdf->cam->z_div;
	point.x -= (fdf->map->width * fdf->cam->zoom) / 2;
	point.y -= (fdf->map->height * fdf->cam->zoom) / 2;
	rotate_x(&point.y, &point.z, fdf->cam->alpha);
	rotate_y(&point.x, &point.z, fdf->cam->beta);
	rotate_z(&point.x, &point.y, fdf->cam->gamma);
	if (fdf->cam->proj == ISO)
		iso(&point.x, &point.y, point.z);
	point.x += (WIDTH) / 2 + fdf->cam->x_offset;
	point.y += (HEIGHT + fdf->map->height * fdf->cam->zoom) / 2
		+ fdf->cam->y_offset;
	return (point);
}
