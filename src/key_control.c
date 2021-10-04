/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:47 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 13:17:49 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*int key_hook(int code, t_fdf *map)
{
    printf("code is %d\n", code);
    return (0);
}*/

int	button_press(int button, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == UP_ARR || button == RIGHT_ARR || button == DOWN_ARR
		|| button == LEFT_ARR)
		move(button, fdf);
	if (button == J_KEY || button == U_KEY || button == K_KEY
		|| button == I_KEY || button == L_KEY || button == O_KEY)
		rotate (button, fdf);
	if (button == MINUS_KEY || button == PLUS_KEY
		|| button == NUM_MINUS_KEY || button == NUM_PLUS_KEY || button == KEY_0)
		zoom(button, fdf);
	if (button == MORE_BUTTON || button == LESS_BUTTON)
		scale(button, fdf);
	if (button == KEY_1 || button == KEY_2 || button == KEY_3
		|| button == KEY_4)
		change_proj(button, fdf);
	if (button == ESC)
		exit(0);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == LEFT_BUTTON)
		fdf->mouse->pressed = 0;
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->pressed = 1;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->prev_x = fdf->mouse->x;
	fdf->mouse->prev_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (!fdf->mouse->pressed)
	{
		fdf->cam->beta += (x - fdf->mouse->prev_x) * 0.001;
		fdf->cam->alpha += (y - fdf->mouse->prev_y) * 0.001;
		print_map(fdf->map, fdf);
	}
	return (0);
}

int	close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
