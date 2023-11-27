/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 05:42:40 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/11/27 23:25:55 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/Cub3D.h"

// void    sliding(t_rayc *rayc)
// {
//     if (map->split_map[(rayc->pp_y + ((int)rayc->y_sin[RAYS / 2])) / 50]
//     [map->pos-x/ 50] != '1' 
//     && rayc->x_cos[RAYS / 2] < 4 && rayc->x_cos[RAYS / 2] > -4)
//     {
//         rayc->pp_y += ((int)rayc->y_sin[RAYS / 2] / 2);
//         map->pos-x -= (int)rayc->x_cos[RAYS / 2];
//         draw_rays(rayc);
//     }
//     else if (map->split_map[rayc->pp_y / 50]
//     [(map->pos-x + ((int)rayc->x_cos[RAYS / 2]))/ 50] != '1' 
//     && rayc->y_sin[RAYS / 2] < 4 && rayc->y_sin[RAYS / 2] > -4)
//     {
//         map->pos-x += ((int)rayc->x_cos[RAYS / 2] / 2);
//         rayc->pp_y -= (int)rayc->y_sin[RAYS / 2];
//         draw_rays(rayc);
//     }
//     else
//     {
//         map->pos-x -= (int)rayc->x_cos[RAYS / 2];
//         rayc->pp_y -= (int)rayc->y_sin[RAYS / 2];
//     }
// }

// int mouse_move(int x, int y, t_rayc *rayc)
// {
//     (void)y;
//     int i = 0;
//     // mlx_mouse_get_pos(rayc->ptr, rayc->window, &rayc->a, &rayc->b);
//     // if (rayc->a >= 700 || rayc->a <= 100)
//     //     mlx_mouse_move(rayc->ptr, rayc->window, RAYS / 2, 300);
//     if (x > rayc->old_x)
//     {
//         if (x >= rayc->old_x + 10)
//             while (i < RAYS)
//             {
//                 rayc->angel[i] += 1.0;
//                 i++;
//             }
//     }
//     else
//     {
//         if (x <= rayc->old_x - 10)
//             while (i < RAYS)
//             {
//                 rayc->angel[i] -= 1.0;
// 				i++;
//             }
//     }
//     draw_rays(rayc);
//     rayc->old_x = x;
//     return (0);
// }

// mlx_mouse_hide(rayc->ptr,rayc->window);
// mlx_hook(rayc->window, 6, 1L << 6, &mouse_move, rayc);
void	game(t_rayc *rayc, t_map *map)
{
	int		x;
	int		dir;
	double	inc;

	x = 0;
	dir = set_player_vision(map);
	rayc->ptr = mlx_init();
	read_textures(rayc, map);
	rayc->window = mlx_new_window(rayc->ptr, WINDOW_WIDTH,
			WINDOW_HIEGHT, "cub3d");
	inc = (double)FOV / (double)RAYS;
	while (x < RAYS)
	{
		rayc->angel[x] = (dir - (FOV / 2)) + inc;
		rayc->ray[x] = 0;
		inc += (double)FOV / (double)RAYS;
		x++;
	}
	rayc->old_x = WINDOW_WIDTH / 2;
	draw_rays(rayc);
	mlx_hook(rayc->window, 3, 3, &player, rayc);
	mlx_hook(rayc->window, 17, 0, &ft_close, rayc);
	mlx_loop(rayc->ptr);
}

int	main(int ac, char **av)
{
	int		x;
	t_rayc	*rayc;
	t_map	*map;

	x = -1;
	rayc = malloc(sizeof(t_rayc));
	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	if (ac == 2)
	{
		map->name = av[1];
		final_check(ac, av, map, rayc);
		rayc->map = map->split_map;
		// ft_free(map->split_map);
		// print(map->split_map);
		while (++x < 5)
			rayc->data[x] = malloc(sizeof(t_data));
		game(rayc, map);
	}
	else
		printf("INVALID ARGS\n");
	free(map);
	return (0);
}
