/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/RTv1.h"

int   main(int argc, char* argv[])
{
  t_mlsdl*    sdl;
  t_scene*    rtv;
  
  rtv = ft_set_scene(argv[1]);
  sdl = ft_init_window(rtv->wd, rtv->height);
  ft_draw_scene(sdl, rtv);
  SDL_UpdateTexture(sdl->txt, NULL, sdl->data->pix, sizeof(Uint32) * rtv->wd);
  mlsdl_put_texture_to_render(sdl->render, sdl->txt);
  mlsdl_loop(sdl);
  mlsdl_close_window(sdl);
  return 0;
}
 