/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:42 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/17 11:44:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	biggest_line(char **map)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (map[i])
	{
		if (line < (int)ft_strlen(map[i]))
			line = (int)ft_strlen(map[i]);
		i++;
	}
	return (line);
}

int   count_line_map(char **map)
{
    int i = 0;
    while (map[i])
        i++;
    return (i);
}

char	*fill_map(int width)
{
	char	*fill_line;
	int		i;

	// fill_line = malloc(sizeof(char) * (width + 3)); 
	fill_line = ft_calloc((width + 3), sizeof(char)); 
	i = 0;
	while (i < width + 2)
	{
		fill_line[i] = 'X';
		i++;
	}
	fill_line[i] = '\0';
	return (fill_line);
}

char	**dup_map(t_map *map, int width, int height)
{
	int	i;
	int	j;
    char **dup =  malloc(sizeof(char *) * (height + 3));
	dup[0] = fill_map(width);
	i = 1;
	while (i < height + 1)
	{
		dup[i] = malloc(sizeof(char) * (width + 3));
		j = 0;
		while (j < width + 2)
		{
			if (j <= (int)ft_strlen(map->split_map[i - 1]) && ft_strchr("10NSWE", map->split_map[i - 1][j - 1]))
				dup[i][j] = map->split_map[i - 1][j - 1];
			else
				dup[i][j] = 'X';
			j++;
		}
		dup[i][j] = '\0';
		i++;
	}
	dup[i] = fill_map(width);
	dup[i + 1] = NULL;
	return (dup);
}

int check_is_open(int i, int j, char **dup)
{
	if (dup[i][j] != 'X' && dup[i][j] != '1')
		return (1);
	return (0);
}

int is_inside_map(int x, int y, int width, int height)
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

int	check_closed_map(char **dup_map, int x, int y, int width, int height)
{
	while (dup_map[y])
	{
		x = 0;
		while (dup_map[y][x])
		{
			if (dup_map[y][x] == 'X')
			{
				if ((dup_map[y][x + 1] && check_is_open(x + 1, y, dup_map)) || (dup_map[y + 1] && check_is_open(x, y + 1, dup_map)))
				{
					ft_free(dup_map);
					return (1);
				}
				else if ((is_inside_map(x - 1, y, width, height) && check_is_open(x - 1, y, dup_map)) || (is_inside_map(x, y - 1, width, height) && check_is_open(x, y - 1, dup_map)))
				{
					ft_free(dup_map);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}


int	check_walls(t_map *map)
{
	char	**dup;
	int		y;
	int		x;
	int		height;
	int		width;

	height = count_line_map(map->split_map);
	width = biggest_line(map->split_map);
	dup = NULL;
	dup = dup_map(map, width, height);
	x = 0;
	y = 0;
	if (check_closed_map(dup, x, y, width, height))
		return (1);
	ft_free(dup);
	return (0);
}

void	final_map_check(t_map *map)
{
	int	i = 0;
	while (map->split_map[i])
	{
		// printf("[%s]\n", map->split_map[i]);
		if (is_valid(map->split_map[i]))
			print_error("Invalid Caracter in the map\n");
		i++;
	}
	if (check_walls(map))
		print_error("Invalid Map\n");
}