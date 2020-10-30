#include "../include/RTv1.h"

t_vec	CanvasToViewport(int i, t_scene *rtv) 
{
	t_vec res;

	res.x = - rtv->width / 2;
	res.y = - rtv->height / 2;

	res.x = ((i % rtv->width) - rtv->width / 2) * rtv->portale->vw / rtv->width; 
	res.y = -((i / rtv->height) - rtv->height / 2) * rtv->portale->vh / rtv->height;
	res.z = rtv->portale->d;

    return (res);
}

t_solution 	ft_intersectraysphere(t_vec *cam_pos, t_vec *D, t_object *object) 
{
	t_solution	solution;
    t_vec		oc;
	float		k1;
	float 		k2;
	float 		k3;
	float 		discriminant;

    solution.t1 = INT_MAX;
	solution.t2 = INT_MAX;
	solution.color = (t_color){0, 0, 0};
	discriminant = -1;
	
	oc = ft_vectorsub(cam_pos, &object->center);
   	k1 = ft_vectordot(D, D);
    k2 = 2 * ft_vectordot(&oc, D);
    k3 = ft_vectordot(&oc, &oc) - pow(object->radius, 2);
	discriminant = pow(k2 , 2) - 4 * k1 * k3;

	if (discriminant < 0)
        return solution;

    solution.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
   	solution.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);

    return (solution);
}

float		ft_calc_light(t_vec n, t_vec p, t_light *light)
{
	float 	intensity;
	t_vec	l;
	float 	n_dot_l;

	intensity = 0.0;

while (light)
	{
	if (light->type == 1)
		intensity += light->intensity;
		else
		{
			if (light->type == 2)
				l = ft_vectorsub(&light->position, &p);
				else
					l = light->direction;
			n_dot_l = ft_vectordot(&n, &l);
			if (n_dot_l >= 0)
			intensity += light->intensity * n_dot_l / (ft_vectorlen(&n) * ft_vectorlen(&l));
		}
		light = light->next;
	}
	return (intensity);
}

int		ft_traceray(t_vec *cam_pos, t_vec d_vec, t_object *objects, t_light *light)
{
    t_solution	solution;
	float		closestt;
	t_object	closest_sphere;
	float		lightt;

	closestt = INT_MAX;
	solution.color = (t_color){0, 0, 0};
	closest_sphere.type = 0;
	
	while (objects)
	{
	    solution = ft_intersectraysphere(cam_pos, &d_vec, objects);
	    
		if ((solution.t1 > 1) && (solution.t1 < INT_MAX) && (solution.t1 < closestt)) 
		{
			closestt = solution.t1;
			closest_sphere = *objects;
		}
		if ((solution.t2 > 1) && (solution.t2 < INT_MAX) && (solution.t2 < closestt))
		{
			closestt = solution.t2;
			closest_sphere = *objects;
		}
		objects = objects->next;
	}
	if (closest_sphere.type == 0)
		return 0x00000000;

	d_vec = ft_vectorscale(&d_vec, closestt);
	t_vec p = ft_vectoradd(cam_pos, &d_vec);
	t_vec n = ft_vectorsub(&p, &closest_sphere.center);
	ft_vectornorm(&n);
	lightt = ft_calc_light(n, p, light);
	return (ft_rgb_to_int(closest_sphere.color.r * lightt, closest_sphere.color.g * lightt, closest_sphere.color.b * lightt)); 
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
	
	while (x < rtv->width * rtv->height)
	{
		sdl->data->pixels[x] = ft_calc_pixel_color(x, rtv);
		x++;
	}
	return 0;
}