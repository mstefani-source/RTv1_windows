/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RTv1.h"

double			clamp(double val, double l, double r)
{
	if (val >= l && val <= r)
		return (val);
	else if (val < l)
		return (l);
	return (r);
}

double			ft_shine(t_vec l, t_vec p, t_vec n)
{
	t_vec	local_norm;
	t_vec	reflect_vec;
	t_vec	to_me;

	to_me = ft_vectorscale(&p, -1);
	ft_vectornorm(&to_me);
	local_norm = ft_vectorscale(&n, ft_vdot(&n, &l));
	reflect_vec = ft_vectorsub(&local_norm, &l);
	reflect_vec = ft_vectoradd(&local_norm, &reflect_vec);
	ft_vectornorm(&reflect_vec);
	return (ft_vdot(&reflect_vec, &to_me));
}

t_solution		*ft_getsol(t_vec p, t_vec vec_to_light, t_object *objects)
{
	t_solution	*sol;

	if (objects->type == 1)
		sol = ft_intersectraysphere(&p, &vec_to_light, objects);
	if (objects->type == 2)
		sol = ft_intersecrayplan(&p, &vec_to_light, objects);
	if (objects->type == 3)
		sol = ft_intersectcyl(&p, &vec_to_light, objects);
	if (objects->type == 4)
		sol = ft_intersectcone(&p, &vec_to_light, objects);
	return (sol);
}

int				ft_check_shadow(t_vec p, t_light *l, t_object *objects)
{
	t_solution	*sol;
	t_vec		vec_to_light;
	double		point;
	double		len_vec_to_light;

	point = INT_MAX;
	vec_to_light = ft_vectorsub(&(l->position), &p);
	len_vec_to_light = ft_vectorlen(&vec_to_light);
	ft_vectornorm(&vec_to_light);
	while (objects)
	{
		sol = ft_getsol(p, vec_to_light, objects);
		if ((sol->t1 > 0.001) && (sol->t1 < INT_MAX) && (sol->t1 < point))
			point = sol->t1;
		if ((sol->t2 > 0.001) && (sol->t2 < INT_MAX) && (sol->t2 < point))
			point = sol->t2;
		if (point > 0 && point < len_vec_to_light)
			return (1);
		objects = objects->next;
	}
	return (0);
}

double			ft_calc_light(t_vec n, t_vec p, t_light *light, double const *s)
{
	t_vec	l;
	double	intensity;
	double	n_dot_l;
	double	shine_int;

	intensity = 0.0;
	shine_int = 0.0;
	if (light->type == 1)
		intensity += light->intensity;
	else
	{
		if (light->type == 2)
			l = ft_vectorsub(&light->position, &p);
		else
			l = light->direction;
		ft_vectornorm(&l);
		n_dot_l = ft_vdot(&n, &l);
		if (n_dot_l > 0)
		{
			shine_int += 0.4 * pow(clamp(ft_shine(l, p, n), 0., 1.), *s);
			intensity += light->intensity * n_dot_l;
		}
	}
	return (intensity + shine_int);
}
