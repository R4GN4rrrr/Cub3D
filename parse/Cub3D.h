/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:55 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/12 22:32:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
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
void	ft_free(char **av);
int my_isspace(char c);
void checkspace(char **array);
void	final_check(t_map *map);

// ------------------LIBFT---------------
void	*ft_calloc(size_t	count, size_t	size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
size_t	ft_strlen(const char *s);
int	ft_strcmp(char *s1, char *s2, char c);


#endif