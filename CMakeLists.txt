cmake_minimum_required(VERSION 3.17)
project(RTv1)

set( CMAKE_C_STANDARD 99 )
set( APP_NAME RTv1 )
set( SRC_DIR ${PROJECT_SOURCE_DIR}/src})

include_directories(gnl)
include_directories(include)
include_directories(libft)
include_directories(mlsdl)
include_directories(SDL)
include_directories(SDL/include)
include_directories(SDL/include/SDL2)

link_directories(mlsdl)
link_directories(libft)
link_directories(SDL/lib)

set(SOURCE_FILES
        gnl/get_next_line.c
        libft/ft_abs.c
        libft/ft_atoi.c
        libft/ft_atoi_base.c
        libft/ft_bzero.c
        libft/ft_factorial.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_islower.c
        libft/ft_ispace.c
        libft/ft_isprint.c
        libft/ft_isupper.c
        libft/ft_itoa.c
        libft/ft_join_and_free.c
        libft/ft_leni.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_overlong.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_rgb_to_int.c
        libft/ft_sqrt.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_vector.c
        libft/ft_vector2.c
        mlsdl/mlsdl_close_window.c
        mlsdl/mlsdl_event_listening.c
        mlsdl/mlsdl_get_data_addr.c
        mlsdl/mlsdl_init.c
        mlsdl/mlsdl_key_press.c
        mlsdl/mlsdl_loop.c
        mlsdl/mlsdl_new_rend.c
        mlsdl/mlsdl_new_surface.c
        mlsdl/mlsdl_new_texture.c
        mlsdl/mlsdl_new_window.c
        mlsdl/mlsdl_put_texture_to_render.c
        mlsdl/mlsdl_update_texture.c
        src/ft_draw_scene.c
        src/ft_init_window.c
        src/ft_intersect_figures.c
        src/ft_light_calc.c
        src/ft_set_scene.c
        src/rtv.c
        src/ft_calc.c)

add_executable(RTv1 ${SOURCE_FILES})

target_link_libraries(${APP_NAME}
        LINK_PUBLIC -lsdl -lm -lSDL2 -lSDL2_image)