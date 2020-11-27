/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_vectorscale(t_vec *v, double n)
{
	t_vec	res;

	res.x = v->x * n;
	res.y = v->y * n;
	res.z = v->z * n;
	return (res);
}

t_vec	ft_vectorsub(t_vec *v1, t_vec *v2)
{
	t_vec	sub;

	sub.x = v1->x - v2->x;
	sub.y = v1->y - v2->y;
	sub.z = v1->z - v2->z;
	return (sub);
}

t_vec	ft_vectorcross(t_vec *v1, t_vec *v2)
{
	t_vec	v;

	v.x = v1->y * v2->z - v1->z * v2->y;
	v.y = v1->z * v2->x - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}

void	ft_vectornorm(t_vec *v)
{
	double	n;

	n = 1.0 / sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

double	ft_vdot(t_vec *v1, t_vec *v2)
{
	double	res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

double	ft_vectorlen(t_vec *v)
{
	return(sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec	ft_vectoradd(t_vec *v1, t_vec *v2)
{
	return((t_vec){v1->x + v2->x, v1->y + v2->y, v1->z + v2->z});
}

double	ft_vec_proj_vec(t_vec *v1, t_vec *v2)
{
	double scal;
	double len;

	scal = ft_vdot(v1, v2);
	len = ft_vectorlen(v2);
	return(scal / len);
}