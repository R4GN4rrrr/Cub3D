/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:25 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/14 15:33:09 by marvin           ###   ########.fr       */
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
        if (current != '0' && current != '1' && current != 'N' 
		&& current != 'S' && current != 'E' && current != 'W')
            return (1);
		i++;
    }
    return (0);
}

int get_path(char *line)
{
	char **splited = ft_split(line, ' ');
	char *path = splited[1];
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
void check_lenght(char **str)
{
	int i = 0;
	int j = -1;
	int check = 0;

	if (ft_strchr(str[0], 'C'))
		str[0] = ft_strtrim(str[0], "C ");
	else
		str[0] = ft_strtrim(str[0], "F ");
	while (str[i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (!ft_isdigit(str[i][j]))
				print_error("only digits");
		}
		if(ft_strlen(str[i]) > 3)
			check += 1;
		i++;
	}
	if ( i > 3 || check)
		print_error("Invalid color format");
}

void	check_digits(char* str)
{
	int i = 0;

	char** color = ft_split(str, ',');
	printf("[%s]\n", str);
	check_lenght(color);
	print(color);
	while (str[i++])
	{
		printf("sjhdqlhsdlsqdl");
		while (my_isspace(str[i]))
			i++;
		if (!(ft_atoi(str) >= 0 && ft_atoi(str) <= 255))
			print_error("invalid range");

	}
	exit(2);
	
	// free(color);
}

void check_textures(t_map *map)
{
	int i = 0;
    char *str;
	
    while (map->count == 6 || map->split_text[i])
    {
		str = map->split_text[i];
        while (my_isspace(*str))
            str++;
        if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0 ||
            ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		{
			get_path(str);
			map->count++;	
		}
		else if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		{
			check_digits(str);
			map->count++;
		}
        else
            print_error("Wrong argument");
		i++;
        
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