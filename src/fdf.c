/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:15:16 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 14:09:22 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	setup_control(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, (1L << 0), button_press, fdf);
	mlx_hook(fdf->mlx_win, 17, 0, close_win, fdf);
	mlx_hook(fdf->mlx_win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->mlx_win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->mlx_win, 6, 0, mouse_move, fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_map	*map;

	if (argc == 2)
	{
		map = map_init(argv[1]);
		read_file(argv[1], map);
		fdf = fdf_init(map);
		fdf->cam = cam_init(fdf);
		print_map(map, fdf);
		setup_control(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		write(1, "Enter file name!\n", 17);
	return (0);
}
