/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_put_texture_to_render.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

void	*mlsdl_put_texture_to_render(SDL_Renderer *sdl_window_render, \
					SDL_Texture *sdl_window_texture)
{
	SDL_RenderClear(sdl_window_render);
	SDL_RenderCopy(sdl_window_render, sdl_window_texture, NULL, NULL);
	SDL_RenderPresent(sdl_window_render);
	return (NULL);
}
