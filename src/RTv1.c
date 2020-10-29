#include  "../include/RTv1.h"

int   main(int argc, char* argv[])
{
  t_mlsdl*    sdl;
  t_scene*    rtv;
  
  rtv = ft_set_scene(argv[1]);
  sdl = ft_init_window(rtv->width, rtv->height);
  
  ft_draw_scene(sdl, rtv);
  SDL_UpdateTexture(sdl->texture, NULL, sdl->data->pixels, sizeof(Uint32) * rtv->width);
  mlsdl_put_texture_to_render(sdl->render, sdl->texture);
  mlsdl_loop(sdl);
  mlsdl_close_window(sdl);
  return 0;
}
 