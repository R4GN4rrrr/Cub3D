/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:32:04 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/11 03:13:39 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	readmap(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	map->str = ft_calloc(1, 1);
	if (line == NULL)
		exit(0);
	while (line)
	{
		map->str = ft_strjoin(map->str, line);
		free(line);
		line = get_next_line(map->fd);
	}
	map->split_map = ft_split(map->str, '\n');
}

// void	check_empty(t_map *map)
// {
// 	char	*line;

// 	map->str = ft_calloc(1, 1);
// 	map->empty_fd = open(map->argv, O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(map->empty_fd);
// 		if (!line)
// 			break ;
// 		map->str = ft_strjoin(map->str, line);
// 		free(line);
// 	}
// 	map->split_file = ft_split(map->str, '\n');
// 	if (!map->split_file || check_space(map->split_file))
// 	{
// 		ft_putstr_fd("Error:\nEmpty file\n", 2);
// 		close(map->empty_fd);
// 		exit(1);
// 	}
// 	free(map->str);
// 	close(map->empty_fd);
// }

void	check_walls(t_map *map)
{
	t_vars	var;

	var.a = 0;
	var.b = 0;
	var.c = ft_strlen(map->split_map[0]) - 1;
	while (map->split_map[0][var.b])
	{
		if (map->split_map[0][var.b] != '1')
			print_error("invalid map!");
		var.b++;
	}
	while (map->split_map[var.a])
	{
		if (map->split_map[var.a][0] != '1')
			print_error("invalid map!");
		if (map->split_map[var.a][var.c] != '1')
			print_error("invalid map!");
		var.a++;
	}
	var.b = -1;
	while (map->split_map[var.a - 1][++var.b])
	{
		if (map->split_map[var.a - 1][var.b] != '1')
			print_error("invalid map!");
	}
}

void	check_args(int ac, char **av, t_map *map)
{
	if (ac != 2)
        print_error("Invalid number of args");
	else if (map_name(map->name))
        print_error(" Invalid file name");
	map->fd = open(av[1], O_RDONLY | __O_DIRECTORY);
	if (map->fd > 0)
	{
		print_error("It's a directory");
		close(map->fd);
	}
	map->fd = open(av[1], O_RDONLY);
	if (map->fd < 0)
        print_error("File does not exist");
	map->argv = av[1];
}