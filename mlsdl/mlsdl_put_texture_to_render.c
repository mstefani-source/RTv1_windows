#include	"mlsdl.h"

void	*mlsdl_put_texture_to_render(SDL_Renderer *sdl_window_render, SDL_Texture *sdl_window_texture)
{
	SDL_RenderClear(sdl_window_render);
  	SDL_RenderCopy(sdl_window_render, sdl_window_texture, NULL, NULL);
  	SDL_RenderPresent(sdl_window_render);
return (NULL);
}