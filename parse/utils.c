/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:59:09 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/13 02:22:27 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	print_error(char *s)
{
	ft_putstr_fd ("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(0);
}

int	map_name(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".cub", 4))
		return (1);
	return (0);
}

int my_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

int	checkspace(char **array)
{
	int i = 0;
	int j;

	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!my_isspace(array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	ft_free(array);
	return (1);
}

void	ft_free(char **av)
{
	int	i;

	i = 0;
	while (av[i++])
		free(av[i]);
	free(av);
}

int	check_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && my_isspace(line[i]))
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	if (ft_strchr("NSWEFC", line[i]))
		return (0);
	return (1);
}