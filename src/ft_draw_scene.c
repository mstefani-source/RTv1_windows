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
	t_vec	temp;

	l = 0.08;
	temp = ft_vectorscale(&np.norm, 1e-4);
	np.pt = ft_vectoradd(&np.pt, &temp);
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

int		ft_draw_scene(t_mlsdl *sdl, t_scene *rtv)
{
	t_vec	direction;
	int		x;
	int		y;

	x = (int)-rtv->wd / 2;
	while (x < rtv->wd / 2)
	{
		y = (int)-rtv->ht / 2;
		while (y < rtv->ht / 2)
		{
			direction = (t_vec){x / rtv->ht, -y / rtv->ht, 1};
			ft_vectornorm(&direction);
			direction = rotate_x(direction, rtv->angle.x * -M_PI / 180.);
			direction = rotate_y(direction, rtv->angle.y * M_PI / 180.);
			direction = rotate_z(direction, rtv->angle.z * M_PI / 180.);
			sdl->data->pix[(x + (int)rtv->wd / 2) + (int)rtv->wd * \
			(y + (int)rtv->ht / 2)] = ft_traceray(rtv->cam_pos, \
			direction, rtv->objects, rtv->light);
			y++;
		}
		x++;
	}
	return (0);
}
