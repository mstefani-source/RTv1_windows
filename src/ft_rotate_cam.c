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

#include "../include/rtv.h"

t_vec rotate_x(t_vec vec, double a)
{
	return (t_vec){
			vec.x,
			vec.y * cos(a) - vec.z * sin(a),
			vec.y * sin(a) + vec.z * cos(a)
	};
}
t_vec rotate_y(t_vec vec, double a)
{
	return (t_vec){
			vec.x * cos(a) + vec.z * sin(a),
			vec.y,
			-vec.x * sin(a) + vec.z * cos(a)
	};
}

t_vec rotate_z(t_vec vec, double a)
{
	return (t_vec){
			vec.x * cos(a) - vec.y * sin(a),
			vec.x * sin(a) + vec.y * cos(a),
			vec.z
	};
}