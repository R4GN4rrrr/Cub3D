NAME = Game

SOURCES = main.c read_map.c utils.c ../get_next_line/get_next_line.c  ../get_next_line/get_next_line_utils.c  utils2.c\
	../Libft/ft_strlen.c ../Libft/ft_calloc.c ../Libft/ft_strjoin.c ../Libft/ft_split.c ../Libft/ft_strncmp.c  ../Libft/ft_strchr.c \
	../Libft/ft_strcmp.c  ../Libft/ft_memset.c\
	../Libft/ft_putstr_fd.c \
	../Libft/ft_bzero.c \

			
OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Werror -Wextra -Wall #-g3 -fsanitize=adress


$(NAME) : $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all