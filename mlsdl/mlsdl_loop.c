#include "mlsdl.h"

void	mlsdl_loop(t_mlsdl *sdl)
{
SDL_Event   event;

while (1) 
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
	 		mlsdl_close_window(sdl);
			break;
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				mlsdl_close_window(sdl);
				break;
			}
		}
	}
}
}