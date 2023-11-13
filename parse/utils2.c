/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:25 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/13 04:50:19 by ymenyoub         ###   ########.fr       */
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

// void check_textures(t_map *map)
// {
// 	int i;
// 	char *path;
//     char *str = map->split_text[i];
//     while (*str)
//     {
//         while (my_isspace)
//             i++;
//         if (ft_strncmp(str, "NO ", 3) == 0)
//         {
//             get_path(path);
//             map->count++;
//         }
//         else if (ft_strncmp(str, "SO ", 3) == 0)
//         {
//             get_path(path);
//             map->count++;
//         }
//         else if (ft_strncmp(str, "WE ", 3) == 0)
//         {
//             get_path(path);
//             map->count++;
//         }
//         else if (ft_strncmp(str, "EA ", 3) == 0)
//         {
//             get_path(path);
//             map->count++;
//         }
//         // else if (ft_strncmp(str, "F ", 2) == 0)
//         // else if (ft_strncmp(str, "C ", 2) == 0)
//         else
//             print_error("Wrong argument");
        
//     }
// }

void composed_map(t_map *map)
{
	int first = 0;
	int last = 0;

	while (map->split_map[first++])
	{
		while (map->split_map[last++])
		{
			if (!is_valid(map->split_map[first][last]))
				print_error("Invalid character in the map");
		}
	}
	// check_walls(map);
}