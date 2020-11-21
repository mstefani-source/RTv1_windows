/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTv1_RTv1_H
# define RTv1_RTv1_H

#include <stdio.h>
#include <stdbool.h>
#include "../mlsdl/mlsdl.h"
#include "../libft/libft.h"
#include "primitives.h"

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_solution
{	
	t_color			color;
	double			t1;
	double			t2;
	int				flag;
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
	t_color			color;
	double			intensity;
	int				type;
	struct s_light	*next;
}					t_light;

typedef struct		s_object
{
	t_vec			norm;
	t_vec			center;
	t_color			color;
	double			radius;
	double			shine;
	int 			type;
    struct s_object	*next;
}					t_object;

typedef struct      s_scene
{
    t_object		*objects;
	t_viewport		*portale;
	t_vec			*cam_pos;
	t_light			*light;
	int				wd;
	int				ht;
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

t_solution 	ft_intersectraysphere(t_vec *cam_pos, t_vec *d, t_object *obj);
t_mlsdl		*ft_init_window(int width, int height);
t_scene		*ft_set_scene(char *file);
int		    ft_draw_scene(t_mlsdl *sdl, t_scene *rtv);
int			ft_check_shadow(t_vec p, t_light *l, t_object *objects);
double		ft_calc_light(t_vec n, t_vec p, t_light *light, double *shine);
double		clamp(double val, double l, double r);

#endif