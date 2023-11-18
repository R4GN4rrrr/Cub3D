/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:51 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/18 07:15:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int main(int ac, char **av)
{
    t_map *map = malloc(sizeof(t_map));  
	ft_memset(map, 0, sizeof(t_map));

    // (void)*av;
    if (ac == 2)
    {
        map->name = av[1];
        final_check(ac, av, map);
    }
    else
        printf("INVALID ARGS\n");
    free(map);
    return 0;
}