/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:51 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/12 22:21:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int main(int ac, char **av)
{
    t_map map;
    (void)*av;
    if (ac == 2)
    {
        printf("%s\n", "TESSSSSSSSST");
        final_check(map);
    }
    else
        printf("INVALID ARGS");
}