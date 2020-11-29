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

#include "../include/rtv.h"

int		ft_fincolor(t_np np, t_object *f_obj, t_light *lt, t_object cl_o)
{
	double	l;

	l = 0.08;
	while (lt)
	{
		if (lt->type == 1)
			l += ft_calc_light(np.norm, np.pt, lt, &cl_o.shine);
		else if (ft_check_shadow(np.pt, lt, f_obj) == 0)
			l += ft_calc_light(np.norm, np.pt, lt, &cl_o.shine);
		lt = lt->next;
	}
	l = clamp(l, 0., 1.);
	return (ft_rgb_to_int(cl_o.col.r * l, cl_o.col.g * l, cl_o.col.b * l));
}

int		ft_traceray(t_vec *cam_pos, t_vec d_vec, t_object *objects, t_light *lt)
{
	t_object	*f_obj;
	t_np		np;
	t_p_o		p_o;

	f_obj = objects;
	p_o = ft_find_point(cam_pos, d_vec, objects);
	if (p_o.point == INT_MAX)
		return (0);
	d_vec = ft_vectorscale(&d_vec, p_o.point);
	np.pt = ft_vectoradd(cam_pos, &d_vec);
	np.norm = ft_calc_norm(np.pt, p_o.cl_o);
	return (ft_fincolor(np, f_obj, lt, p_o.cl_o));
}

t_vec	canvastoviewport(int i, t_scene *rtv)
{
	t_vec res;

	res.x = -rtv->wd / 2.0;
	res.y = -rtv->ht / 2.0;
	res.x = ((i % (int)rtv->wd) - rtv->wd / 2) * rtv->port->vw / rtv->wd;
	res.y = -((i / rtv->ht) - rtv->ht / 2) * rtv->port->vh / rtv->ht;
	res.z = rtv->port->d;
	return (res);
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
		sdl->data->pix[x] = ft_calc_pixel_color(x, rtv);
		x++;
	}
	return (0);
}
