#include "libft.h"

int			ft_rgb_to_int(int red, int green, int blue)
{
	int		r;
	int		g;
	int		b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 24 | g << 16 | b << 8);
}