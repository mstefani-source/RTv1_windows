/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_new_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

SDL_Window		*mlsdl_new_window(int width, int height, char *title)
{
	SDL_Window	*sdl_window_pointer;

	sdl_window_pointer = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, \
									SDL_WINDOWPOS_CENTERED, width, height, 0);
	if (!sdl_window_pointer)
		return ((void *)0);
	return (sdl_window_pointer);
}
