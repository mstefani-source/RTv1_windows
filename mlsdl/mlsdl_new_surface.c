#include "mlsdl.h"

SDL_Surface        *mlsdl_new_surface(SDL_Window *sdl_window_pointer, int width, int height)
{
	SDL_Surface* screen;

	screen = SDL_CreateRGBSurface(0, width, height, 8, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	if (!screen)
		return ((void *)0);	
	return (screen); 
}