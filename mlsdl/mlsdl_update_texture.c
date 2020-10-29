#include "mlsdl.h"
	
void	mlsdl_update_texture(SDL_Texture *sdl_window_texture, char* pixels)
{
	int			width, height;
	Uint32		format;

	SDL_QueryTexture(sdl_window_texture, &format, NULL, &width, &height);
	SDL_UpdateTexture(sdl_window_texture, NULL, pixels, width * sizeof(Uint32));
}