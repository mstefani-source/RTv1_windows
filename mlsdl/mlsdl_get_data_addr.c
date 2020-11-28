/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_get_data_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"
#include "../libft/libft.h"

char			*mlsdl_get_data_addr(SDL_Texture *sdl_window_texture, \
							int *bits_per_pixel, int *size_line, int *endian)
{
	char		*pixels;
	int			width;
	int			height;
	Uint32		format;
	uint16_t	x;

	x = 1;
	SDL_QueryTexture(sdl_window_texture, &format, NULL, &width, &height);
	pixels = malloc(width * height * sizeof(Uint32));
	ft_memset(pixels, 1, width * height * sizeof(Uint32));
	*endian = ((uint8_t*)&x) ? 1 : 0;
	*bits_per_pixel = sizeof(Uint32);
	*size_line = sizeof(Uint32) * width;
	return (pixels);
}
