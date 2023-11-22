/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:24:08 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/22 17:38:53 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	find_start_position(t_map *map)
{
	int		i;
	int		j;
	char	current;

	i = 0;
	while (map->split_map[i])
	{
		j = 0;
		while (map->split_map[i][j])
		{
			current = map->split_map[i][j];
			if (current == 'N' || current == 'S' || current == 'E'
				|| current == 'W')
			{
				map->player_found++;
				map->pos_x = j;
				map->pos_y = i;
				map->Caracter = current;
			}
			j++;
		}
		i++;
	}
	if (map->player_found > 1)
		print_error("More than 1 player in the map\n");
	return (0);
}

void	set_player_vision(t_map *map)
{
	if (map->vision == 'N')
		map->player_angle = 3 * (M_PI / 2);
	if (map->vision == 'S')
		map->player_angle = M_PI / 2;
	if (map->vision == 'W')
		map->player_angle = 0;
	if (map->vision == 'E')
		map->player_angle = M_PI;
}

void	check_args(char **av, t_map *map)
{
	if (map_name(map->name))
		print_error("Invalid file name\n");
	map->fd = open(av[1], O_RDONLY | __O_DIRECTORY);
	if (map->fd > 0)
	{
		print_error("It's a directory\n");
		close(map->fd);
	}
	map->fd = open(av[1], O_RDONLY);
	if (map->fd < 0)
		print_error("File does not exist\n");
	map->argv = av[1];
}
void	print(char **pr)
{
	int i;

	i = 0;
	while (pr[i])
	{
		printf("%s", pr[i++]);
		printf("\n");
	}
}