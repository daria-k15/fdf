/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:23:10 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 14:42:06 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	find_max(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float	find_min(float x, float y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	zoom_def(t_fdf *fdf)
{
	int	zoom_width;
	int	zoom_height;
	int	zoom;

	zoom_width = (WIDTH / fdf->map->width) / 3;
	zoom_height = HEIGHT / fdf->map->height / 3;
	zoom = find_min(zoom_width, zoom_height);
	return (zoom);
}
