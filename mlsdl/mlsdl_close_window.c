#include "mlsdl.h"

void	*mlsdl_close_window(t_mlsdl *sdl)
{
 	if (sdl->txt)
		SDL_DestroyTexture(sdl->txt);
 	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->pointer)
		SDL_DestroyWindow(sdl->pointer);
	SDL_Quit(); 
	return (NULL); 
}