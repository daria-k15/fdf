#include "fdf.h"
#include "libft/include/libft.h"
#include "mlx/mlx.h"

int main(int argc, char **argv)
{
    t_map *map;
    // t_fdf *fdf;

    if (argc == 2)
    {
        map = map_init(argv[1]);
        read_file(argv[1], map);
        // int i = 0;
        // while (i < map->height)
        // {
        //     int j = 0;
        //     while (j <= map->width)
        //     {
        //         printf("%3d", map->matrix[i][j]);
        //         j++;
        //     }
        //     printf("\n");
        //     i++;
        // }
    }
}