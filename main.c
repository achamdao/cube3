/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:00:39 by achamdao          #+#    #+#             */
/*   Updated: 2025/07/24 14:22:08 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub.h"

// void f()
// {
//     system("leaks cube");
// }
// void print_matrix(char **matrix)
// {
//     int i = 0;
//     while (matrix[i])
//     {
//         printf("%s", matrix[i]);
//         i++;
//     }
// }

// void    free_info_cub(t_info_cub *info_cube)
// {
//     free_matrex(info_cube->parts_file.part_paths);
//     free_matrex(info_cube->parts_file.part_colors);
//     if (!info_cube->map)
//         free_matrex(info_cube->parts_file.part_map);
//     free_matrex(info_cube->map);
//     free(info_cube->wall_east);
//     free(info_cube->wall_north);
//     free(info_cube->wall_south);
//     free(info_cube->wall_west);
// }

// char    parsing_info(int argc, char **argv, t_info_cub *info_cube)
// {
//     char    **file;

//     if (check_input(argc, argv))
//         return (1);
//     file = stored_map(argv[1]);
//     if(storted_parts(file, &info_cube->parts_file))
//         return (1);
//     if (parse_paths(info_cube))
//         return (free_info_cub(info_cube), ft_putendl_fd("Error\nInvalid path!!", 2), 1);
//     if (parse_colors(info_cube))
//         return (free_info_cub(info_cube), ft_putendl_fd("Error\nInvalid color!!", 2),  1);
//     if (parse_map(info_cube->parts_file.part_map, info_cube))
//         return (free_info_cub(info_cube), ft_putendl_fd("Error\nInvalid map!!", 2),  1);
//     return (0);
// }

// int main(int argc, char **argv)
// {
//     t_info_cub info_cub;
    
//     // atexit(f);
//     ft_memset(&info_cub, 0, sizeof(info_cub));
//     if (parsing_info(argc, argv, &info_cub))
//         return (1);
//     ft_putendl_fd(info_cub.wall_east, 1);
//     ft_putendl_fd(info_cub.wall_west, 1);
//     ft_putendl_fd(info_cub.wall_south, 1);
//     ft_putendl_fd(info_cub.wall_north, 1);
//     printf("C red %d \n", info_cub.ceiling.red);
//     printf("C green %d \n", info_cub.ceiling.green);
//     printf("C blue %d \n", info_cub.ceiling.blue);
//    printf("F red %d \n", info_cub.floor.red);
//     printf("F green %d \n", info_cub.floor.green);
//     printf("F blue %d \n", info_cub.floor.blue);
//     printf("Pos x player %f \n", info_cub.x);
//     printf("Pos y player %f \n", info_cub.y);
//     print_matrix(info_cub.map);
//     free_info_cub(&info_cub);
//     return (0);
// }
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

void draw_vertical_line(void *mlx, void *win, int x, int y_start, int y_end, int color)
{
    if (y_start > y_end)
    {
        int temp = y_start;
        y_start = y_end;
        y_end = temp;
    }

    for (int y = y_start; y <= y_end; y++)
    {
        mlx_pixel_put(mlx, win, x, y, color);
    }
}

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define TILE 10000
#define FOV (M_PI / 3)  // 60°
#define NUM_RAYS WIDTH  // شعاع لكل بكسل عرض
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "11111111",
    "10000001",
    "10111001",
    "10001001",
    "10101101",
    "10000001",
    "10000001",
    "11111111"
};

int is_wall(float x, float y)
{
    int mx = (int)(x / TILE);
    int my = (int)(y / TILE);
    if (mx < 0 || my < 0 || mx >= MAP_WIDTH || my >= MAP_HEIGHT)
        return 1;
    return map[my][mx] == '1';
}

void draw_line(void *mlx, void *win, int x, int height, int color)
{
    int start = (HEIGHT / 2) - (height / 2);
    int end = start + height;
    for (int y = start; y < end; y++)
    {
        if (y >= 0 && y < HEIGHT)
            mlx_pixel_put(mlx, win, x, y, color);
    }
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Raycasting Basic");

    float player_x = 3 * TILE;
    float player_y = 3 * TILE;
    float player_angle = M_PI / 4; // 45°

    for (int ray = 0; ray < NUM_RAYS; ray++)
    {
        float ray_angle = player_angle - (FOV / 2) + ((float)ray / NUM_RAYS) * FOV;

        float ray_x = player_x;
        float ray_y = player_y;
        float step = 1;
        float distance = 0;

        while (1)
        {
            ray_x = player_x + cos(ray_angle) * distance;
            ray_y = player_y + sin(ray_angle) * distance;

            if (is_wall(ray_x, ray_y))
                break;
            distance += step;
        }

        // تصحيح الانحراف البصري (Fish-eye)
        float corrected = distance * cos(ray_angle - player_angle);

        // حساب طول الجدار
        int wall_height = (int)(TILE * HEIGHT / corrected);

        // رسم خط عمودي بلون أحمر
        draw_line(mlx, win, ray, wall_height, 0xFF0000);
    }

    mlx_loop(mlx);
    return 0;
}
