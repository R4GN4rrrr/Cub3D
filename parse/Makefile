NAME = Cub3D

SOURCES = main.c read_map.c get_next_line\
			
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