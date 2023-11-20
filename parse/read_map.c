/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:32:04 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/20 10:47:56 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	read_map_rd(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->split_text[i++])
		map->width++;
	map->split_map = ft_calloc(sizeof(char *), map->width - map->count + 1);
	i = map->count;
	while (map->split_text[i])
	{
		map->split_map[j] = ft_strdup(map->split_text[i]);
		// printf("%s\n", map->split_map[j]);
		if (map->split_map[j] && map->split_map[j][0] == '\n')
		{
			printf("hdgaskfjgaskfgas\n");
			print_error("There is a new line in the map\n");
		}
		i++;
		j++;
	}
	map->split_map[j] = NULL;
	ft_free(map->split_text);
	// print(map->split_map);
}

void	print(char **pr)
{
	int	i;

	i = 0;
	while (pr[i])
	{
		printf("%s", pr[i++]);
		printf("\n");
	}
}

void	read_textures(t_map *map)
{
	char	*line;
	int		checker;

	map->str = ft_calloc(1, 1);
	checker = 0;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (line[0] == ' ' || line[0] == '1')
			checker = 1;
		if (checker == 1 && line[0] == '\n')
			print_error("Invalid Map1\n");
		map->str = ft_strjoin(map->str, line);
		free(line);
	}
	map->split_text = ft_split(map->str, '\n');
	free(map->str);
	// print(map->split_text);
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
		print_error("Empty file!\n");
		close(map->empty_fd);
	}
	free(map->str);
	close(map->empty_fd);
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
