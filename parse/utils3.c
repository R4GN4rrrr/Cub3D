/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:24:08 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/21 09:16:29 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"  

int find_start_position(t_map *map)
{
    int i = 0;
    int j;

    while (map->split_map[i])
    {
        j = 0;
        while (map->split_map[i][j])
        {
            char current = map->split_map[i][j];
            if (current == 'N' || current == 'S' || current == 'E' || current == 'W')
            {
                map->player_found++;
                map->pos_x = j;
                map->pos_y = i;
                map->Caracter = current;
                // printf("%c\n", map->Caracter);
            }
            j++;
        }
        i++;
    }
    // printf("player: %d\n", map->player_found);
    if (map->player_found > 1)
        print_error("More than 1 player in the map\n");
    return (0); 
}


void    set_player_vision(t_map *map)
{
    if (map->vision == 'N')
		map->player_angle = M_PI / 2;
	if (map->vision== 'S')
		map->player_angle = 3 * (M_PI / 2);
	if (map->vision== 'W')
		map->player_angle = M_PI;
	if (map->vision== 'E')
		map->player_angle = 0;
}