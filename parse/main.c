/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:51 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/25 03:48:51 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	get_path(char *line)
{
	int		fd;
	char	**splited;

	fd = 0;
	splited = ft_split(line, ' ');
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

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	if (ac == 2)
	{
		map->name = av[1];
		final_check(ac, av, map);
	}
	else
		printf("INVALID ARGS\n");
	free(map);
	return (0);
}
