/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:32:04 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/18 07:49:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	read_map_rd(t_map *map)
{

	int i = 0;
	int j = 0;

	while (map->split_text[i++])
		map->width++;
	map->split_map = ft_calloc(sizeof(char*), map->width - map->count + 1);
	i = map->count;
	while (map->split_text[i])
	{
		map->split_map[j] = ft_strdup(map->split_text[i]);
		i++;
		j++;
	}
	map->split_map[j] = NULL;
	ft_free(map->split_text);
	print(map->split_map);





	// int i= 0;
	// int j = 0;
	// while (map->split_text[i++])
	// 	map->width++;
	// // print(map->split_text);
	// // printf("[%d]\n", map->count);
	// // exit(5);
	// map->split_map = ft_calloc(sizeof(char*), map->width - map->count + 1);
	// printf("%s\n", map->split_text[i + map->count]);
	// exit(5);
	// while (map->split_text[i + map->count])
	// {

	// 	// map->split_map[j] = ft_strdup(map->split_text[i + map->count ]);
	// 	// printf("%s\n",map->split_map[j]);
	// 	// exit(7);
	// 	// map->str = ft_calloc(1, 1);
	// 	// map->str = ft_strjoin(map->str, line);
	// 	// free(line);
	// 	// while (1)
	// 	// {
	// 	// 	line = get_next_line(fd);
	// 	// 	// if (!line) //salat map
	// 	// 	// 	break ;
	// 	// 	map->str = ft_strjoin(map->str, line);
	// 	// 	free(line);
	// 	// }
	// 	// map->split_map = ft_split(map->str, '\n');
	// 	i++;
	// 	j++;
	// }
	// map->split_map[j] = 0;
	// print(map->split_map);
	// exit(0);
	// else
	// {
	// 	print_error("No Map!!\n");
	// 	close(map->fd);
	// }
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
		// if (check_map(line))
		// 	break ;
		map->str = ft_strjoin(map->str, line);
		free(line);
		line = get_next_line(map->fd);
	}
	// free(line);
	map->split_text = ft_split(map->str, '\n');
	free (map->str);
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
	read_map_rd(map);
	final_map_check(map);
}