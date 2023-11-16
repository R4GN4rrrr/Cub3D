/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:42 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/16 08:18:18 by marvin           ###   ########.fr       */
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
		if (line < ft_strlen(map[i]))
			line = ft_strlen(map[i]);
		i++;
	}
	return (line);
}

int   count_line_map(char **map)
{
    int i = 0;
    while (map[i])
        i++;
    return (i)
}

char	*fill_map(int width)
{
	char	*fill_line;
	int		i;

	fill_line = malloc(sizeof(char) * (width + 3)); 
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
			if (j <= ft_strlen(map->split_map[i - 1]) && ft_strchr("10NSWE", map->split_map[i - 1][j - 1]))
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
