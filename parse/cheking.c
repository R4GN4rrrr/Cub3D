/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:42 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/21 09:09:44 by ymenyoub         ###   ########.fr       */
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

int	count_line_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	*fill_map(int width, char *line)
{
	char	*fill_line;
	int		i;
	int		j;

	fill_line = ft_calloc((width + 3), sizeof(char));
	i = 0;
	if (line)
		fill_line[i++] = 'X';
	j = 0;
	while (i < width + 2)
	{
		if (line && j < (int)ft_strlen(line) && ft_strchr("10NSWE", line[j]))
			fill_line[i] = line[j];
		else
			fill_line[i] = 'X';
		i++;
		j++;
	}
	fill_line[i] = '\0';
	return (fill_line);
}

char	**dup_map(t_map *map, int width, int height)
{
	int		i;
	char	**dup;
	int		j;

	dup = ft_calloc(height + 3, sizeof(char *));
	dup[0] = fill_map(width, NULL);
	i = 1;
	j = 0;
	while (i < height + 1)
	{
		dup[i] = fill_map(width, map->split_map[j]);
		i++;
		j++;
	}
	dup[i] = fill_map(width, NULL);
	dup[i + 1] = NULL;
	// print(dup);
	return (dup);
}

int	check_is_open(int i, int j, char **dup)
{
	if (dup[j][i] != 'X' && dup[j][i] != '1')
		return (1);
	return (0);
}

int	is_inside_map(int x, int y, int width, int height)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

int	check_closed_map(char **dup_map, int x, int y, int width, int height)
{
	while (dup_map[y])
	{
		x = 0;
		// printf("%d\n", x);
		while (dup_map[y][x])
		{
			if (dup_map[y][x] == 'X')
			{
				if ((dup_map[y][x + 1] && check_is_open(x + 1, y, dup_map))
					|| (dup_map[y + 1] && check_is_open(x, y + 1, dup_map)))
				{
					ft_free(dup_map);
					return (1);
				}
				else if ((is_inside_map(x - 1, y, width, height)
							&& check_is_open(x - 1, y, dup_map))
						|| (is_inside_map(x, y - 1, width, height)
							&& check_is_open(x, y - 1, dup_map)))
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
	if (!dup || check_closed_map(dup, x, y, width, height))
		return (1);
	ft_free(dup);
	return (0);
}

void	final_map_check(t_map *map)
{
	int	i;

	i = 0;
	while (map->split_map[i])
	{
		if (is_valid(map->split_map[i]))
			print_error("Invalid Caracter in the map\n");
		i++;
	}
	find_start_position(map);
	if (check_walls(map))
		print_error("Invalid Map\n");
}
