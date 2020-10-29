#include "mlsdl.h"

char             *mlsdl_get_data_addr(SDL_Texture *sdl_window_texture, int *bits_per_pixel, int *size_line, int *endian)
{
	char		*pixels;
	int			width, height;
	Uint32		format;
	uint16_t 	x = 1;       /* 0x0001 */

	SDL_QueryTexture(sdl_window_texture, &format, NULL, &width, &height);
	
	pixels = malloc(width * height * sizeof(Uint32));
  	memset(pixels, 1, width * height * sizeof(Uint32));
	
	*endian = ((uint8_t *) & x) ? 1 : 0;
	
	*bits_per_pixel = sizeof(Uint32);
	*size_line = sizeof(Uint32) * width;

	return (pixels);
}