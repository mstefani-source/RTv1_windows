#include "mlsdl.h"

int 	mlsdl_init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	return (1);
}