#include "mlsdl.h"

SDL_Renderer       *mlsdl_new_rend(SDL_Window *sdl_ptr)
{
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* sdl_render = SDL_CreateRenderer(sdl_ptr, -1, render_flags);
		if (!sdl_render)
			return ((void *)0);
	return (sdl_render);
}
