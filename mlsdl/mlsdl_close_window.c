/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_close_window.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

void	*mlsdl_close_window(t_mlsdl *sdl)
{
	if (sdl->txt)
		SDL_DestroyTexture(sdl->txt);
	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->pointer)
		SDL_DestroyWindow(sdl->pointer);
	SDL_Quit();
	return (NULL);
}
