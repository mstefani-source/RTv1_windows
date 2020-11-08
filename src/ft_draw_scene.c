/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_scene.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RTv1.h"

t_vec	CanvasToViewport(int i, t_scene *rtv) 
{
	t_vec res;

	res.x = - rtv->wd / 2;
	res.y = - rtv->ht / 2;

	res.x = ((i % rtv->wd) - rtv->wd / 2) * rtv->portale->vw / rtv->wd; 
	res.y = -((i / rtv->ht) - rtv->ht / 2) * rtv->portale->vh / rtv->ht;
	res.z = rtv->portale->d;

    return (res);
}

t_solution 	ft_intersectraysphere(t_vec *cam_pos, t_vec *D, t_object *object) 
{
	t_solution	sol;
    t_vec		oc;
	float		k1;
	float 		k2;
	float 		k3;
	float 		discriminant;

    sol.t1 = INT_MAX;
	sol.t2 = INT_MAX;
	sol.color = (t_color){0, 0, 0};
	discriminant = -1;
	
	oc = ft_vectorsub(cam_pos, &object->center);
   	k1 = ft_vectordot(D, D);
    k2 = 2 * ft_vectordot(&oc, D);
    k3 = ft_vectordot(&oc, &oc) - pow(object->radius, 2);
	discriminant = pow(k2 , 2) - 4 * k1 * k3;

	if (discriminant < 0)
        return sol;

    sol.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
   	sol.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);

    return (sol);
}

double		ft_calc_shine(t_vec l, t_vec p, t_vec n)
{
	double 	res;
	t_vec	local_norm;
	t_vec	reflect_vec;
	t_vec	to_me;

	to_me = ft_vectorscale(&p, -1);
	ft_vectornorm(&to_me);

	local_norm = ft_vectorscale(&n ,ft_vectordot(&n, &l));
	reflect_vec = ft_vectorsub(&local_norm, &l);
	reflect_vec = ft_vectoradd(&local_norm, &reflect_vec);
	ft_vectornorm(&reflect_vec);

	return (ft_vectordot(&reflect_vec, &to_me));
}

double		clamp(double val, double l, double r) {
	if (val >= l && val <= r)
		return val;
	else if (val < l)
		return l;
	return r;
}

double		ft_calc_light(t_vec n, t_vec p, t_light *light, double *shine)
{
	t_vec	l;
	double	intensity;
	double	n_dot_l;
	double	shine_int;

	intensity = 0.0;
	shine_int = 0.0;

while (light)
	{
	if (light->type == 1)
		intensity += light->intensity;
		else
		{
			if (light->type == 2)
			{
				l = ft_vectorsub(&light->position, &p);
				ft_vectornorm(&l);
			}
			else 
			{
				l = light->direction;
				ft_vectornorm(&l);
			}
			n_dot_l = ft_vectordot(&n, &l);
			if (n_dot_l >= 0)
			{
 				shine_int +=  0.4 * pow(ft_calc_shine(l, p, n), *shine);
				intensity += light->intensity * n_dot_l;
			}
		}
		light = light->next;
	}
	return (clamp(intensity + shine_int, 0., 1.));
}

int		ft_traceray(t_vec *cam_pos, t_vec d_vec, t_object *objects, t_light *lt)
{
    t_solution	sol;
	t_object	closest_sphere;
	float		point;
	float		ltt;

	point = INT_MAX;
	sol.color = (t_color){0, 0, 0};
	closest_sphere.type = 0;
	
	while (objects)
	{
	    sol = ft_intersectraysphere(cam_pos, &d_vec, objects);
	    
		if ((sol.t1 > 1) && (sol.t1 < INT_MAX) && (sol.t1 < point)) 
		{
			point = sol.t1;
			closest_sphere = *objects;
		}
		if ((sol.t2 > 1) && (sol.t2 < INT_MAX) && (sol.t2 < point))
		{
			point = sol.t2;
			closest_sphere = *objects;
		}
		objects = objects->next;
	}
	if (closest_sphere.type == 0)
		return 0x00000000;

	d_vec = ft_vectorscale(&d_vec, point);
	t_vec p = ft_vectoradd(cam_pos, &d_vec);
	t_vec n = ft_vectorsub(&p, &closest_sphere.center);
	ft_vectornorm(&n);
	ltt = ft_calc_light(n, p, lt, &closest_sphere.shine);

	return (ft_rgb_to_int(closest_sphere.color.r * ltt, closest_sphere.color.g * ltt, closest_sphere.color.b * ltt)); 
}

int 	ft_calc_pixel_color(int point_on_canvas, t_scene *rtv)
{
	t_vec	point_on_viewport;
	t_vec	d_vec;
	int color;

	point_on_viewport = CanvasToViewport(point_on_canvas, rtv);
	d_vec = ft_vectorsub(&point_on_viewport, rtv->cam_pos);
	color = ft_traceray(rtv->cam_pos, d_vec, rtv->objects, rtv->light);

	return (color);
}

int		ft_draw_scene(t_mlsdl *sdl, t_scene *rtv)
{
	int 	x = 0;
	
	while (x < rtv->wd * rtv->ht)
	{
		sdl->data->pix[x] = ft_calc_pixel_color(x, rtv);
		x++;
	}
	return 0;
}