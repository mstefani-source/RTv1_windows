NAME = RTv1

SRC = src/rtv.c \
	gnl/get_next_line.c \
	src/ft_init_window.c \
	src/ft_draw_scene.c \
	src/ft_light_calc.c \
	src/ft_intersect_figures.c \
	src/ft_calc.c \
	src/ft_atof.c \
	src/ft_rotate_cam.c \
	src/ft_parce_scene.c \
	src/ft_pars_in_details.c \
	src/ft_all_objects.c

INCLUDES = -I/usr/local/include -ISDL/include/ -Iinclude -Imlsdl -Ilibft

LIBOBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
SDLFLAGS = -L./mlsdl -L./SDL/lib

C_CYAN = \033[36m

all: $(NAME)

$(NAME): $(LIBOBJ) $(D_SDL)
		make -C ./libft
		make -C ./mlsdl
		gcc $(CFLAGS) $(LIBOBJ) $(INCLUDES) -L./libft -L./mlsdl $(SDLFLAGS) -lft -lm -lSDL2 -lSDL2_image -o $(NAME)
%.o:%.c include/rtv.h
		gcc -MD -g -c $<  -o $@

clean:
	make -C ./libft clean
	make -C ./mlsdl clean
	-rm -rf $(LIBOBJ)
	-rm -f src/*.d

fclean: clean
	make -C ./libft fclean
	make -C ./mlsdl fclean
	-rm -f $(NAME)
	-rm -f src/*.d

re: fclean all
