/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2020/11/30 20:55:57 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_vdot(t_vec *v1, t_vec *v2)
{
	double	res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

double	ft_vectorlen(t_vec *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec	ft_vectoradd(t_vec *v1, t_vec *v2)
{
	return ((t_vec){v1->x + v2->x, v1->y + v2->y, v1->z + v2->z, v1->i});
}

double	ft_vec_proj_vec(t_vec *v1, t_vec *v2)
{
	double scal;
	double len;

	scal = ft_vdot(v1, v2);
	len = ft_vectorlen(v2);
	return (scal / len);
}
