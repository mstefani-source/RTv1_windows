/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlsdl_event_listening.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlsdl.h"

void			key_listing(void)
{
	SDL_Event	event;
	int			app_running;
	int			key[500];

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			app_running = 0;
		if (event.type == SDL_KEYDOWN)
			key[event.key.keysym.sym] = 1;
		if (event.type == SDL_KEYUP)
			key[event.key.keysym.sym] = 0;
	}
}
