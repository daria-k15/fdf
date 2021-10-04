/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:18:06 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 13:18:07 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	move(int button, t_fdf *fdf)
{
	if (button == UP_ARR)
		fdf->cam->y_offset -= 10;
	else if (button == RIGHT_ARR)
		fdf->cam->x_offset += 10;
	else if (button == DOWN_ARR)
		fdf->cam->y_offset += 10;
	else if (button == LEFT_ARR)
		fdf->cam->x_offset -= 10;
	print_map(fdf->map, fdf);
}

void	rotate(int button, t_fdf *fdf)
{
	if (button == J_KEY)
		fdf->cam->alpha -= 0.05;
	if (button == U_KEY)
		fdf->cam->alpha += 0.05;
	if (button == K_KEY)
		fdf->cam->beta -= 0.05;
	if (button == I_KEY)
		fdf->cam->beta += 0.05;
	if (button == L_KEY)
		fdf->cam->gamma -= 0.05;
	if (button == O_KEY)
		fdf->cam->gamma += 0.05;
	print_map(fdf->map, fdf);
}

void	zoom(int button, t_fdf *fdf)
{
	if (button == MINUS_KEY || button == NUM_MINUS_KEY || button == SCROLL_DOWN)
		fdf->cam->zoom--;
	else if (button == PLUS_KEY || button == NUM_PLUS_KEY
		|| button == SCROLL_UP)
		fdf->cam->zoom++;
	else if (button == KEY_0)
	{
		fdf->cam->zoom = zoom_def(fdf);
		fdf->cam->x_offset = 0;
		fdf->cam->y_offset = 0;
	}
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	print_map(fdf->map, fdf);
}

void	scale(int button, t_fdf *fdf)
{
	if (button == LESS_BUTTON)
		fdf->cam->z_div /= 1.1;
	if (button == MORE_BUTTON)
		fdf->cam->z_div *= 1.1;
	if (fdf->cam->z_div < 0.1)
		fdf->cam->z_div = 0.1;
	else if (fdf->cam->z_div > fdf->cam->zoom)
		fdf->cam->z_div = fdf->cam->zoom;
	print_map(fdf->map, fdf);
}

void	change_proj(int button, t_fdf *fdf)
{
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
	if (button == KEY_1)
		fdf->cam->proj = TOP;
	else if (button == KEY_2)
	{
		fdf->cam->proj = SIDE;
		fdf->cam->alpha = -1.570796;
	}
	else if (button == KEY_3)
	{
		fdf->cam->proj = FRONT;
		fdf->cam->alpha = -1.570796;
		fdf->cam->beta = -1.570796;
	}
	else if (button == KEY_4)
		fdf->cam->proj = ISO;
	print_map(fdf->map, fdf);
}
