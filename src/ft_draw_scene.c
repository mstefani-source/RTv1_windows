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

t_vec	canvastoviewport(int i, t_scene *rtv)
{
	t_vec res;

	res.x = -rtv->wd / 2.0;
	res.y = -rtv->ht / 2.0;
	res.x = ((i % rtv->wd) - rtv->wd / 2) * rtv->portale->vw / rtv->wd;
	res.y = -((i / rtv->ht) - rtv->ht / 2) * rtv->portale->vh / rtv->ht;
	res.z = rtv->portale->d;
	return (res);
}

int		ft_traceray(t_vec *cam_pos, t_vec d_vec, t_object *objects, t_light *lt)
{
	t_solution	*sol;
	t_object	cl_o;
	t_object	*f_obj;
	t_vec		p;
	t_vec		n;
	double		point;
	double		l;

	l = 0.08;
	f_obj = objects;
	point = INT_MAX;
	cl_o.type = 0;

	while (objects)
	{
		sol = ft_getsol(*cam_pos, d_vec, objects);
		if ((sol->t1 > 1) && (sol->t1 < INT_MAX) && (sol->t1 < point))
		{
			point = sol->t1;
			cl_o = *objects;
		}
		if ((sol->t2 > 1) && (sol->t2 < INT_MAX) && (sol->t2 < point))
		{
			point = sol->t2;
			cl_o = *objects;
		}
		objects = objects->next;
	}
	if (point == INT_MAX)
		return (0);
	d_vec = ft_vectorscale(&d_vec, point);
	p = ft_vectoradd(cam_pos, &d_vec);
	if (cl_o.type == 1)
		n = ft_vectorsub(&p, &cl_o.center);
	if (cl_o.type == 2)
		n = cl_o.n;
	if ((cl_o.type == 3) || (cl_o.type == 4))
	{
		t_vec cp = ft_vectorsub(&p, &cl_o.center);
		ft_vectornorm(&cl_o.n);
		ft_vectornorm(&cp);
		double a = ft_vdot(&cp,&cl_o.n);
		t_vec q = ft_vectorscale(&cl_o.n, a);
		n = ft_vectorsub(&cp, &q);
	}
	ft_vectornorm(&n);
	while (lt)
	{
		if (lt->type == 1)
			l += ft_calc_light(n, p, lt, &cl_o.shine);
		else if (ft_check_shadow(p, lt, f_obj) == 0)
			l += ft_calc_light(n, p, lt, &cl_o.shine);
		lt = lt->next;
	}
	l = clamp(l, 0., 1.);
	return (ft_rgb_to_int(cl_o.col.r * l, cl_o.col.g * l, cl_o.col.b * l));
}

int		ft_calc_pixel_color(int point_on_canvas, t_scene *rtv)
{
	t_vec	point_on_viewport;
	t_vec	d_vec;
	int		color;

	point_on_viewport = canvastoviewport(point_on_canvas, rtv);
	d_vec = ft_vectorsub(&point_on_viewport, rtv->cam_pos);
	color = ft_traceray(rtv->cam_pos, d_vec, rtv->objects, rtv->light);
	return (color);
}

int		ft_draw_scene(t_mlsdl *sdl, t_scene *rtv)
{
	int		x;

	x = 0;
	while (x < rtv->wd * rtv->ht)
	{
		if (x == 800 * 700 + 100)
			x = x - 1 + 1;
		sdl->data->pix[x] = ft_calc_pixel_color(x, rtv);
		x++;
	}
	return (0);
}
