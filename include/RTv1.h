#ifndef RTv1_RTv1_H
# define RTv1_RTv1_H

#include <stdio.h>
#include <stdbool.h>
#include "../mlsdl/mlsdl.h"
#include "../libft/libft.h"
#include "primitives.h"
#define WIDTH 640
#define HEIGHT 640

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_solution
{
	float			t1;
	float			t2;
	t_color			color;
}					t_solution;

typedef struct      s_viewport
{
    double			d;
    float			vw;
    float			vh;
}                   t_viewport;

typedef	struct		s_light
{
	int				type;
	float			intensity;
	t_vec			position;
	t_vec			direction;
	struct s_light	*next;
}					t_light;

typedef struct		s_object
{
	int 			type;
	t_vec			center;
	int				radius;
	t_vec			norm;
	t_color			color;
    struct s_object	*next;
}					t_object;

typedef struct      s_scene
{
    t_object		*objects;
	t_viewport		*portale;
	t_vec			*cam_pos;
	t_light			*light;
	int				width;
	int				height;
}                   t_scene;

typedef struct		s_wnd
{
	void			*ptr;
	void			*wnd;
	void			*img;
	char			*data_addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
}					t_wnd;

t_mlsdl		*ft_init_window(int width, int height);
t_scene		*ft_set_scene(char *file);
int		    ft_draw_scene(t_mlsdl *sdl, t_scene *rtv);

#endif