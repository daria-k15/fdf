/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:12:32 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 13:12:36 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	double	per;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		per = percent(start.x, end.x, current.x);
	else
		per = percent(start.y, end.y, current.y);
	return (rgb(get_light(get_r(start.color), get_r(end.color), per),
			get_light(get_g(start.color), get_g(end.color), per),
			get_light(get_b(start.color), get_b(end.color), per)));
}
