/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:24:25 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/19 03:46:25 by ymenyoub         ###   ########.fr       */
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
		if (current != '0' && current != '1' && current != 'N' && current != 'S' 
		&& current != 'E' && current != 'W' && current != ' ')
			return (1);
		i++;
	}
	return (0);
}

void get_path(char *line)
{
	int fd = 0;
	char **splited = ft_split(line, ' ');

	fd = open(splited[1], O_RDONLY | __O_DIRECTORY);
	if (fd > 0)
	{
		ft_free(splited);
		close(fd);
		print_error("It's a directory\n");
	}
	fd = open(splited[1], O_RDONLY);
	if (fd < 0)
	{
		ft_free(splited);
		print_error("Wrong Texture File\n");
	}
	if (ft_strncmp(splited[1] + (ft_strlen(splited[1]) - 4), ".xpm", 4))
	{
		ft_free(splited);
		print_error("Wrong Texture File\n");
	}
	ft_free(splited);
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
				print_error("only digits\n");
		}
		if (ft_strlen(str[i]) > 3)
			check += 1;
		i++;
	}
	if (i > 3 || check)
		print_error("Invalid color format\n");
}

void check_digits(char *str)
{
	int i = 0;

	char **color = ft_split(str, ',');
	check_lenght(color);
	while (color[i])
	{
		if (!((ft_atoi(color[i]) >= 0) && (ft_atoi(color[i]) <= 255)))
			print_error("invalid range [0,255]\n");
		i++;
	}
	ft_free(color);
}

void check_textures_id(char *str, t_vars *id)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		id->no++;
	else if (ft_strncmp(str, "SO ", 3) == 0)
		id->so++;
	else if (ft_strncmp(str, "EA ", 3) == 0)
		id->ea++;
	else if (ft_strncmp(str, "WE ", 3) == 0)
		id->we++;
	else if (ft_strncmp(str, "F ", 2) == 0)
		id->f++;
	else if (ft_strncmp(str, "C ", 2) == 0)
		id->c++;
	if (id->no > 1 || id->c > 1 || id->ea > 1 || id->so > 1 || id->f > 1 || id->we > 1)
		print_error("Duplicated id\n");
}

void check_textures(t_map *map)
{
	int i = 0;
	char *str = NULL;
	map->count = 0;
	t_vars vars;
	ft_memset(&vars, 0, sizeof(t_vars));

	while (map->split_text[i] && map->count != 6)
	{
		str = map->split_text[i];
		while (my_isspace(*str))
			str++;
		if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0 ||
			ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		{
			check_textures_id(str, &vars);
			get_path(str);
			map->count++;
		}
		else if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		{
			check_textures_id(str, &vars);
			check_digits(str);
			map->count++;
		}
		else
			print_error("Wrong textures id\n");
		i++;
	}
}
