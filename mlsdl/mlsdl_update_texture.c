/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_update_texturer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

void		mlsdl_update_texture(SDL_Texture *sdl_window_texture, char *pixels)
{
	int		width;
	int		height;
	Uint32	format;

	SDL_QueryTexture(sdl_window_texture, &format, NULL, &width, &height);
	SDL_UpdateTexture(sdl_window_texture, NULL, pixels, width * sizeof(Uint32));
}
