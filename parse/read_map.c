/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:32:04 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/16 07:48:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	read_map(int fd, t_map *map, char *line)
{
	if (line)
	{
		map->str = ft_calloc(1, 1);
		map->str = ft_strjoin(map->str, line);
		free(line);
		while (1)
		{
			line = get_next_line(fd);
			if (!line) //salat map
				break ;
			map->str = ft_strjoin(map->str, line);
			free(line);
		}
		map->split_map = ft_split(map->str, '\n');
	}
	else
	{
		print_error("No Map!!");
		close(map->fd);
	}
}

void print(char **pr)
{
	int i = 0;
	while (pr[i])
	{
		printf("%s", pr[i++]);
		printf("\n");
	}
}

void	read_textures(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	map->str = ft_calloc(1, 1);
	if (line == NULL)
		exit(0);
	while (line)
	{
		if (check_map(line))
			break ;
		map->str = ft_strjoin(map->str, line);
		free(line);
		line = get_next_line(map->fd);
	}
	map->split_text = ft_split(map->str, '\n');
	free (map->str);
	read_map(map->fd, map, line);
	close(map->fd);
}


void	empty_file(t_map *map)
{
	char	*line;

	map->str = ft_calloc(1, 1);
	map->empty_fd = open(map->argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(map->empty_fd);
		if (!line)
			break ;
		map->str = ft_strjoin(map->str, line);
		free(line);
	}
	map->split_file = ft_split(map->str, '\n');
	if (!map->split_file || checkspace(map->split_file))
	{
		print_error("Empty file! ");
		close(map->empty_fd);
	}
	free(map->str);
	close(map->empty_fd);
}


void	check_args(char **av, t_map *map)
{
	if (map_name(map->name))
			print_error("Invalid file name");	
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


void	final_check(int ac, char **av, t_map *map)
{
	(void)ac;
	check_args(av, map);
	empty_file(map);
	read_textures(map);
	check_textures(map);
}