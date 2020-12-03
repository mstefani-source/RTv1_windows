/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

t_vec		ft_calc_norm(t_vec p, t_object cl_o)
{
	t_vec	norm;
	t_vec	cp;
	t_vec	q;
	double	a;

	if (cl_o.type == 0)
		norm = (t_vec){0., 0., 0.};
	if (cl_o.type == 1)
		norm = ft_vectorsub(&p, &cl_o.center);
	if (cl_o.type == 2)
		norm = cl_o.n;
	if ((cl_o.type == 3) || (cl_o.type == 4))
	{
		cp = ft_vectorsub(&p, &cl_o.center);
		ft_vectornorm(&cl_o.n);
		ft_vectornorm(&cp);
		a = ft_vdot(&cp, &cl_o.n);
		q = ft_vectorscale(&cl_o.n, a);
		norm = ft_vectorsub(&cp, &q);
	}
	ft_vectornorm(&norm);
	return (norm);
}

t_p_o		ft_find_point(t_vec *cam_pos, t_vec d_vec, t_object *objects)
{
	t_p_o		p_o;
	t_solution	sol;

	p_o.point = INT_MAX;
	while (objects)
	{
		sol = ft_getsol(*cam_pos, d_vec, objects);
		if ((sol.t1 > 1) && (sol.t1 < INT_MAX) && (sol.t1 < p_o.point))
		{
			p_o.point = sol.t1;
			p_o.cl_o = *objects;
		}
		objects = objects->next;
	}
	return (p_o);
}

t_solution	ft_biggest_sol(t_solution sol)
{
	double temp;

	if (sol.t1 > sol.t2)
	{
		temp = sol.t1;
		sol.t1 = sol.t2;
		sol.t2 = temp;
	}
	if (sol.t1 < 0)
	{
		sol.t1 = sol.t2;
		if (sol.t1 < 0)
			sol.t1 = INT_MAX;
	}
	return sol;
}