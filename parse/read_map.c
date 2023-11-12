/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:32:04 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/12 07:50:48 by marvin           ###   ########.fr       */
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

void	check_empty(t_map *map)
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
	if (!map->split_file || check_space(map->split_file))
	{
		print_error("Empty file");
		close(map->empty_fd);
	}
	free(map->str);
	close(map->empty_fd);
}

void	check_walls(t_map *map)
{
	t_vars	var;

	var.a = 0;
	var.b = 0;
	var.c = ft_strlen(map->split_map[0]) - 1;
	while (map->split_map[0][var.b])
	{
		if (map->split_map[0][var.b] != '1')
			print_error("invalid map! Map must be closed/surrounded by walls. ");
		var.b++;
	}
	while (map->split_map[var.a])
	{
		if (map->split_map[var.a][0] != '1')
			print_error("invalid map! Map must be closed/surrounded by walls. ");
		if (map->split_map[var.a][var.c] != '1')
			print_error("invalid map! Map must be closed/surrounded by walls. ");
		var.a++;
	}
	var.b = -1;
	while (map->split_map[var.a - 1][++var.b])
	{
		if (map->split_map[var.a - 1][var.b] != '1')
			print_error("invalid map! Map must be closed/surrounded by walls. ");
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

int is_valid(char *map)
{
	char current;
	int i = 0;
    while (map[i])
	{
        current = map[i];
        if (current != '0' && current != '1' && current != 'N' && current != 'S' && current != 'E' && current != 'W')
            return (1);
		i++;
    }
    return (0);
}

int is_space(char *map)
{
    char current;
    int i = 0;
    while (map[i]) {
        current = map[i];
        if (current != ' ')
		{
            if (!is_valid(map))
                return (1); 
        }
        i++;
    }
    return (0);
}

int get_path(char *path)
{
    int path_len = ft_strlen(path);

    if (path_len < 4)
		return (0);
    if (ft_strcmp(path + path_len - 4, ".xpm") == 0) 
        return (1); 
    return (0);
}

void check_text(t_map *map)
{
    char *str = map->split_map[i];
	char *path;
	int i;

    if (ft_strncmp(str, "NO ", 3) == 0)
    else if (ft_strncmp(str, "SO ", 3) == 0)
    else if (ft_strncmp(str, "WE ", 3) == 0)
    else if (ft_strncmp(str, "EA ", 3) == 0)
    // else if (ft_strncmp(str, "F ", 2) == 0)
    // else if (ft_strncmp(str, "C ", 2) == 0)
    else
    {
       print_error("Wrong argument");
    }
}

void composed_map(t_map *map)
{
	int first = 0;
	int last = 0;

	while (map->split_map[first++])
	{
		while (map->split_map[last++])
		{
			if (!is_valid(map->split_map[first][last]))
				print_error("Invalid character in the map")
		}
	}
	// check_walls(map);

}
