#include "fdf.h"

int get_height(char *name)
{
    int fd;
    char *line;
    int height;

    height = 0;
    fd = open(name, O_RDONLY);
    while (get_next_line(fd, &line))
        height++;
    free(line);
    close(fd);
    return(height);
}

int get_width(char *name)
{
    int fd;
    int width;
    char *line;

    width = 0;
    fd = open(name, O_RDONLY);
    get_next_line(fd, &line);
    width = word_count(line, ' ');
    free(line);
    close(fd);
    return(width);
}

void    get_val(int *val, char *line)
{
    int i;
    char **parts;

    i = 0;
    parts = ft_split(line, ' ');
    while (parts[i])
    {
        val[i] = ft_atoi(parts[i]);
        free(parts[i]);
        i++;
    }
    free(parts);
}

void    read_file(char *name, t_map *map)
{
    int fd;
    char *line;
    int i;

    i = 0;
    map->height = get_height(name);
    map->width = get_width(name);
    map->matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
    while (i <= map->height)
        map->matrix[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
    fd = open(name, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line))
    {
        get_val(map->matrix[i], line);
        free(line);
        i++;
    }
    free(line);
    close(fd);
}