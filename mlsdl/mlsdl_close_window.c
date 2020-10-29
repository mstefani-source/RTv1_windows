#include "mlsdl.h"

void	*mlsdl_close_window(t_mlsdl *sdl)
{
	
	/* Release resources */


 	if (sdl->texture)
		SDL_DestroyTexture(sdl->texture);
 	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->pointer)
		SDL_DestroyWindow(sdl->pointer);
	SDL_Quit(); 
	return (NULL); 
}