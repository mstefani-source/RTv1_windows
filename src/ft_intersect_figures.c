/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_figures                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

t_solution		*ft_initsol(void)
{
	t_solution *res;

	res = (t_solution*)malloc(sizeof(t_solution));
	res->t1 = INT_MAX;
	res->t2 = INT_MAX;
	res->color = (t_color){0, 0, 0};
	res->point = INT_MAX;
	res->object = NULL;
	return (res);
}

t_solution		*ft_intersectraysphere(t_vec *cam_pos, t_vec *d, t_object *obj)
{
	t_solution	*sol;
	t_vec		oc;
	double		k2;
	double		k3;
	double		discriminant;

	sol = ft_initsol();
	oc = ft_vectorsub(cam_pos, &obj->center);
	k2 = 2 * ft_vdot(&oc, d);
	k3 = ft_vdot(&oc, &oc) - pow(obj->radius, 2);
	discriminant = pow(k2, 2) - 4 * ft_vdot(d, d) * k3;
	if ((discriminant) < 0)
		return (sol);
	sol->t1 = (-k2 + sqrt(discriminant)) / (2 * ft_vdot(d, d));
	sol->t2 = (-k2 - sqrt(discriminant)) / (2 * ft_vdot(d, d));
	sol->color = obj->col;
	return (sol);
}

t_solution		*ft_intersecrayplan(t_vec *cam_pos, t_vec *d_vec, t_object *obj)
{
	t_solution	*sol;
	t_vec		a;

	sol = ft_initsol();
	a = ft_vectorsub(&obj->center, cam_pos);
	sol->t1 = (ft_vdot(&a, &(obj->n)) / ft_vdot(d_vec, &(obj->n)));
	return (sol);
}

t_solution		*ft_intersectcyl(t_vec *cam_pos, t_vec *d, t_object *obj)
{
	t_solution	*sol;
	t_vec		oc;
	double		k1;
	double		k2;
	double		k3;

	sol = ft_initsol();
	oc = ft_vectorsub(cam_pos, &obj->center);
	k1 = ft_vdot(d, d) - ft_vdot(d, &(obj->n)) * ft_vdot(d, &(obj->n));
	k2 = 2 * ft_vdot(&oc, d) - ft_vdot(d, &(obj->n)) * ft_vdot(&oc, &(obj->n));
	k3 = ft_vdot(&oc, &oc) - pow(obj->radius, 2) - ft_vdot(&oc, &(obj->n)) \
													* ft_vdot(&oc, &(obj->n));
	if ((pow(k2, 2) - 4 * k1 * k3) < 0)
		return (sol);
	sol->t1 = (-k2 + sqrt(pow(k2, 2) - 4 * k1 * k3)) / (2 * k1);
	sol->t2 = (-k2 - sqrt(pow(k2, 2) - 4 * k1 * k3)) / (2 * k1);
	sol->color = obj->col;
	return (sol);
}

t_solution		*ft_intersectcone(t_vec *cam_pos, t_vec *d, t_object *obj)
{
	t_solution	*sol;
	t_vec		oc;
	double		k1;
	double		k2;
	double		k3;

	sol = ft_initsol();
	oc = ft_vectorsub(cam_pos, &obj->center);
	ft_vectornorm(&(obj->n));
	k1 = ft_vdot(d, d) - ft_vdot(d, &(obj->n)) * ft_vdot(d, &(obj->n)) * (1.13);
	k2 = 2 * ft_vdot(&oc, d) - (ft_vdot(d, &(obj->n)) \
							* ft_vdot(&oc, &(obj->n)) * 1.13);
	k3 = ft_vdot(&oc, &oc) - pow(obj->radius, 2) * 1.13;
	if ((pow(k2, 2) - 4 * k1 * k3) < 0)
		return (sol);
	sol->t1 = (-k2 + sqrt(pow(k2, 2) - 4 * k1 * k3)) / (2 * k1);
	sol->t2 = (-k2 - sqrt(pow(k2, 2) - 4 * k1 * k3)) / (2 * k1);
	sol->color = obj->col;
	return (sol);
}
