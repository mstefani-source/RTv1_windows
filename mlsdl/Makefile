# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 16:30:02 by mstefani          #+#    #+#              #
#    Updated: 2020/02/12 18:45:17 by mstefani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsdl.a

HEADERS = .

SRC = mlsdl_close_window.c \
		mlsdl_event_listening.c \
		mlsdl_get_data_addr.c \
		mlsdl_init.c \
		mlsdl_loop.c \
		mlsdl_new_rend.c \
		mlsdl_new_texture.c \
		mlsdl_new_window.c \
		mlsdl_put_texture_to_render.c \
		mlsdl_update_texture.c

CFLAGS = -Wall

OBJ=$(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) $(SRC) mlsdl.h
	gcc -c $(CFLAGS) $(SRC) -I $(HEADERS)
	ar rc $(NAME) $?
	ranlib $(NAME) 

%.o:%.c libft.h
	gcc $(CFLAGS) $< -c -o $@

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re:	fclean all
