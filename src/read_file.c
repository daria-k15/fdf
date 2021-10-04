/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:23:01 by heveline          #+#    #+#             */
/*   Updated: 2021/08/17 14:07:23 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	word_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (count);
	if (str[i] != c)
	{
		count ++;
		i++;
	}
	i--;
	while (str[++i + 1] != '\0')
		if (str[i] == c && str[i + 1] != c)
			count++;
	return (count);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	map_size(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	map->height = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		width = word_count(line, ' ');
		if (map->height == 0)
			map->width = width;
		else if (map->width != width)
			ft_putstr("check  Error in reading map file!\n");
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
	map->size = map->height * map->width;
	return (map->size);
}

void	get_data(char **matrix, t_map *map)
{
	char		**parts;

	while (*matrix)
	{
		parts = ft_split(*(matrix++), ',');
		if (!parts)
			ft_putstr("Error in reading map file!\n");
		map->points[map->i].x = map->i % (map->width);
		map->points[map->i].y = map->i / (map->width);
		map->points[map->i].z = ft_atoi(parts[0]);
		if (map->points[map->i].z > map->z_max)
			map->z_max = map->points[map->i].z;
		if (map->points[map->i].z < map->z_min)
			map->z_min = map->points[map->i].z;
		map->i++;
		free_split(parts);
	}
}

int	read_file(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**matrix;

	map->i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		matrix = ft_split(line, ' ');
		get_data(matrix, map);
		free_split(matrix);
		free(line);
	}
	free(line);
	set_default_color(map);
	close(fd);
	return (0);
}
