/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:31:55 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/11/20 11:08:40 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_vars
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}			t_vars;

typedef struct s_map
{
	int		player_found;
	double 	player_angle;
	int		pos_x;
	int		pos_y;
	char 	vision;
	int		count;
	char	*str;
	int		fd;
	char	**split_map;
	char	**split_text;
	char	**split_file;
	char	**split_arg;
	int		empty_fd;
	char	*name;
	char	*argv;
	int		width;
}			t_map;

void		print(char **pr);

// --------------------CUB3D--------------
void		read_map_rd(t_map *map);
void		read_textures(t_map *map);
int			map_name(char *name);
void		print_error(char *s);
int			my_isspace(char c);
int			checkspace(char **array);
void		final_check(int ac, char **av, t_map *map);
int			check_map(char *line);
void		check_textures(t_map *map);
void		composed_map(t_map *map);
int			is_valid(char *map);
void		ft_free(char **av);
void		final_map_check(t_map *map);
int 	find_start_position(t_map *map);

// ------------------LIBFT---------------
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2, char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif