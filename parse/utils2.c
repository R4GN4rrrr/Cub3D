/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:25 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/13 07:03:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

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

int get_path(char *path)
{
    int path_len = ft_strlen(path);

    if (path_len < 4)
		return (0);
    // map->fd = open(av[1], O_RDONLY | __O_DIRECTORY);
	// if (map->fd > 0)
	// {
	// 	print_error("It's a directory");
	// 	close(map->fd);
	// }
	// map->fd = open(av[1], O_RDONLY);
		// if (map->fd < 0)
    //     print_error("File does not exist");
    if (ft_strncmp(path + (path_len - 4), ".xpm", 4) == 0) 
        return (1); 
    return (0);
}

void check_textures(t_map *map)
{
	int i = 0;
	char *path = NULL;
    char *str;
	char *color_str;
	int len;

    while (str && *str)
    {
		str = map->split_text[i];
        while (my_isspace(*str))
            str++;
        if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0 ||
            ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		{
			get_path(path);
			map->count++;	
		}
		else if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		{
			color_str = str + 2;
			len = 0;
			while (color_str[len] && color_str[len] != ',')
			{
				if (!ft_isdigit(color_str[len]))
					print_error("Invalid color format");
				len++;
				if (color_str[len] > 3)
					print_error("Bad Format!!");
			}
			if (color_str[len] != ',')
				print_error("Invalid color format");
			int r = ft_atoi(color_str);
			int g = ft_atoi(color_str + len + 1);
			int b = ft_atoi(color_str + len + 2);
			if  (!((r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)))
				print_error("Invalid RGB values. Must be in the range [0, 255]");
			map->count++;
		}
        else
            print_error("Wrong argument");
        
    }
}

// void composed_map(t_map *map)
// {
// 	int first = 0;
// 	int last = 0;

// 	while (map->split_map[first++])
// 	{
// 		while (map->split_map[last++])
// 		{
// 			if (!is_valid(map->split_map[first][last]))
// 				print_error("Invalid character in the map");
// 		}
// 	}
// 	// check_walls(map);
// }