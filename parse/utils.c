/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:59:09 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/11 03:10:54 by ymenyoub         ###   ########.fr       */
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