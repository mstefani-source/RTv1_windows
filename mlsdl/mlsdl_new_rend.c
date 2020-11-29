/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_new_rend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

SDL_Renderer		*mlsdl_new_rend(SDL_Window *sdl_ptr)
{
	Uint32			render_flags;
	SDL_Renderer	*sdl_render;

	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	sdl_render = SDL_CreateRenderer(sdl_ptr, -1, render_flags);
	if (!sdl_render)
		return ((void *)0);
	return (sdl_render);
}
