#include "fdf.h"

double  percentage(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    if (distance == 0)
        return(1.0);
    else
        return(placement / distance);
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int create_rgb(int r, int g, int b)
{
    return (r << 16 | g << 8| b);
}

// int get_color(t_map current, t_map a, t_map b, t_map delta)
// {
//     double percentage;

//     if (current.color == b.color)
//         return (current.color);
//     if ()
// }