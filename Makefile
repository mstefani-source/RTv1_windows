NAME = RTv1

SRC = src/RTv1.c \
	gnl/get_next_line.c \
	src/ft_init_window.c \
	src/ft_draw_scene.c \
	src/ft_set_scene.c \
	src/ft_light_calc.c \
	src/ft_intersect_figures.c

INCLUDES = -I/usr/local/include -ISDL/include/ -Iinclude -Imlsdl -Ilibft

LIBOBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
SDLFLAGS = -L./mlsdl -L./SDL/lib

C_CYAN = \033[36m

all: $(NAME)

$(NAME): $(LIBOBJ) $(D_SDL)
		make -C ./libft
		make -C ./mlsdl
		gcc $(CFLAGS) $(LIBOBJ) $(INCLUDES) -L./libft  $(SDLFLAGS) -lft -lsdl -lSDL2 -lSDL2_Image -o $(NAME)
%.o:%.c include/RTv1.h
		gcc -MD -g -O0 -c $<  -o $@

clean:
	make -C ./libft clean
	make -C ./mlsdl clean
	-rm -rf $(LIBOBJ)
	-rm -f src/*.d

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)
	-rm -f src/*.d

re: fclean all
