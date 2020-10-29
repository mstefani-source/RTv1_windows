#include "mlsdl.h"

void 	key_listing()
{
	SDL_Event event;
	int app_running;
	int key[500];

  	if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) app_running = 0;
        if (event.type == SDL_KEYDOWN) key[event.key.keysym.sym]=1;
        if (event.type == SDL_KEYUP) key[event.key.keysym.sym]=0;
    }
}