#include "fdf.h"


size_t  map_size(char *name, t_map *map)
{
    int fd;
    char *str;
    int width;

    width = 0;
    map->height = 0;
    fd = open(name, O_RDONLY);
    while (get_next_line(fd, &str))
    {
        width = word_count(str, ' ');
        if (map->height == 0)
            map->width = width;
        else if (map->width != width)
            printf("Map is invalid!\n"); /*invalid comment*/
        map->height++;
        free(str);
    }
    close(fd);
    map->size = map->height * map->width;
    return(sizeof(t_map) * map->size);
}

t_map *map_init(char *name)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return(NULL);
    // map->matrix = (t_map *)malloc(map_size(name, map));
    // if (!map->points)
    //     return (NULL);
    map->z_max = INT_MIN;
    map->z_min = INT_MAX;
    map->height = 0;
    map->width = 0;
    return (map);
}