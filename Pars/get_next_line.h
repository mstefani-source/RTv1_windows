#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>
# include <sys/stat.h>
# include <limits.h>

/*typedef struct      s_color
{
	int             r;
	int             g;
	int             b;
}                   t_color;

typedef struct      s_vec
{
	double          x;
	double          y;
	double          z;
}                   t_vec;

typedef struct		s_solution
{
	t_color			color;
	double			t1;
	double			t2;
}					t_solution;

typedef struct      s_viewport
{
	double			d;
	double			vw;
	double			vh;
}                   t_viewport;

typedef	struct		s_light
{
	t_vec			position;
	t_vec			direction;
	double			intensity;
	int				type;
	struct s_light	*next;
}					t_light;

typedef struct      s_object
{
	t_vec           norm;
	t_vec           center;
	t_color         color;
	double 			angle;
	double          radius;
	double          shine;
	int             type;
	struct s_object *next;
}                   t_object;

typedef struct      s_scene
{
	t_object		*objects;
	t_viewport		*portale;
	t_vec			*cam_pos;
	t_light			*light;
	int				width;
	int				height;
}                   t_scene;*/



#endif
