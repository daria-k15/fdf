/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:11:53 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 13:11:59 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	set_default_color(t_map *map)
{
	int		i;
	double	per;

	i = 0;
	while (i < map->size)
	{
		per = percent(map->z_min, map->z_max, map->points[i].z);
		map->points[i].color = rgb(get_light(get_r(LOW), get_r(HIGH), per),
				get_light(get_g(LOW), get_g(HIGH), per),
				get_light(get_b(LOW), get_b(HIGH), per));
		i++;
	}
}
