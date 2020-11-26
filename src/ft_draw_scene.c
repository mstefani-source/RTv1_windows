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

	res.x = - rtv->wd / 2.0;
	res.y = - rtv->ht / 2.0;

	res.x = ((i % rtv->wd) - rtv->wd / 2) * rtv->portale->vw / rtv->wd; 
	res.y = -((i / rtv->ht) - rtv->ht / 2) * rtv->portale->vh / rtv->ht;
	res.z = rtv->portale->d;

    return (res);
}

int		ft_traceray(t_vec *cam_pos, t_vec d_vec, t_object *objects, t_light *lt)
{
    t_solution	*sol;
	t_object	closest_object;
	t_object	*f_obj;
	t_vec 		p;
	t_vec 		n;
	double		point;
	double		ltt;

	ltt = 0.08;
	f_obj = objects;
	point = INT_MAX;
	closest_object.type = 0;

	// пересекает ли луч из камеры какую либо фигуру?
	while (objects)
	{
		if (objects->type == 1)
	    	sol = ft_intersectraysphere(cam_pos, &d_vec, objects);
  		if (objects->type == 2)
			sol = ft_intersectrayplan(cam_pos, &d_vec, objects);
		if (objects->type == 3)
			sol = ft_intersectcyl(cam_pos, &d_vec, objects);	
		if (objects->type == 4)
			sol = ft_intersectcone(cam_pos, &d_vec, objects);

		if ((sol->t1 > 1) && (sol->t1 < INT_MAX) && (sol->t1 < point)) 
		{
			point = sol->t1;
			closest_object = *objects;
		}
 		if ((sol->t2 > 1) && (sol->t2 < INT_MAX) && (sol->t2 < point))
		{
			point = sol->t2;
			closest_object = *objects;
		} 
		objects = objects->next;
	}
	if (point == INT_MAX)
		return (0);
	
	d_vec = ft_vectorscale(&d_vec, point);  	// вычисляем 
	p = ft_vectoradd(cam_pos, &d_vec);   	  	// вектор до точки
 	if (closest_object.type == 1)
		n = ft_vectorsub(&p, &closest_object.center); // вычисяем 
	if (closest_object.type == 2)
		n = closest_object.norm; 
	if (closest_object.type == 3)
	{
		t_vec cp = ft_vectorsub(&p, &closest_object.center);
		ft_vectornorm(&closest_object.norm);
		ft_vectornorm(&cp);
		double a = ft_vectordot(&cp,&closest_object.norm);
		t_vec q = ft_vectorscale(&closest_object.norm, a);
		n = ft_vectorsub(&cp, &q);
	}
	if (closest_object.type == 4)
	{
		t_vec cp = ft_vectorsub(&p, &closest_object.center);
		ft_vectornorm(&closest_object.norm);
		ft_vectornorm(&cp);
		double a = ft_vectordot(&cp,&closest_object.norm);
		t_vec q = ft_vectorscale(&closest_object.norm, a);
		n = ft_vectorsub(&cp, &q);
	}
	ft_vectornorm(&n);							 // нормаль в этой точке

	while (lt)
	{
		if (lt->type == 1)
		{
			ltt += ft_calc_light(n, p, lt, &closest_object.shine);
		}
		else
			if (ft_check_shadow(p, lt, f_obj) == 0)
				ltt += ft_calc_light(n, p, lt, &closest_object.shine);
		lt = lt->next;
	}
	ltt = clamp(ltt, 0., 1.);
	return (ft_rgb_to_int(closest_object.color.r * ltt, closest_object.color.g * ltt, closest_object.color.b * ltt)); 
}

int 	ft_calc_pixel_color(int point_on_canvas, t_scene *rtv)
{
	t_vec	point_on_viewport;
	t_vec	d_vec;
	int		color;

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
		if (x == 800 * 700 + 100) {
			x = x - 1 + 1;
		}
		sdl->data->pix[x] = ft_calc_pixel_color(x, rtv);
		x++;
	}
	return 0;
}