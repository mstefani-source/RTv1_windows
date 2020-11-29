/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_new_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

SDL_Texture		*mlsdl_new_texture(SDL_Renderer *sdl_render, int w, int h)
{
	SDL_Texture *texture;

	texture = SDL_CreateTexture(sdl_render, SDL_PIXELFORMAT_RGBA8888, \
									SDL_TEXTUREACCESS_TARGET, w, h);
	return (texture);
}
