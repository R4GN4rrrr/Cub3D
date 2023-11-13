/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:51 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/13 03:16:40 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int main(int ac, char **av)
{
    t_map *map = malloc(sizeof(t_map));
    // (void)*av;
    if (ac == 2)
    {
        map->name = av[1];
        final_check(ac, av, map);
    }
    else
        printf("INVALID ARGS");
    free(map);
}