/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:55 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/12 04:34:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../Libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <mlx.h>
#include <fcntl.h>

typedef struct s_vars
{
	int	a;
	int	b;
	int	c;
}	t_vars;

typedef struct s_map
{
	int		count;
	char	*str;
	int		fd;
	int		pos_x;
	int		pos_y;
	char	**split_map;
	char	**split_file;
	int		empty_fd;
	char 	*name;
	char	*argv;
} t_map;

// --------------------CUB3D--------------
void	readmap(t_map *map);
int	map_name(char *name);
void	print_error(char *s);

// ------------------LIBFT---------------
void	*ft_calloc(size_t	count, size_t	size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif