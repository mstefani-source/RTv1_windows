#include "mlsdl.h"

SDL_Texture        *mlsdl_new_texture(SDL_Renderer *sdl_window_render, int width, int height)
{
	SDL_Texture *texture;
	
	texture = SDL_CreateTexture(sdl_window_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	return (texture);
}