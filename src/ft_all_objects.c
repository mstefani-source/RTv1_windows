/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:51:56 by skale             #+#    #+#             */
/*   Updated: 2020/12/01 18:06:54 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

t_object		*ft_add_plane(t_object *object, char *line)
{
	t_object	*new_object;
	int			i;

	i = 0;
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		return(0);
	new_object->type = 2;
	new_object->center = ft_vec(i, line, new_object->center, 2);
	i = new_object->center.i;
	i = ft_next_space(i, line);
	new_object->n = ft_vec(i, line, new_object->n, 1);
	i = new_object->n.i;
	new_object->col = ft_color(i, line, new_object->col);
	i = new_object->col.i;
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_object->shine = ft_atof(&line[i]);
	new_object->next = object;
	if (new_object->shine < 0)
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (new_object);
}

t_object		*ft_add_sphere(t_object *object, char *line)
{
	t_object	*new_object;
	int			i;

	i = 0;
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		return (0);
	new_object->type = 1;
	new_object->center = ft_vec(i, line, new_object->center, 2);
	i = new_object->center.i;
	new_object->col = ft_color(i, line, new_object->col);
	i = new_object->col.i;
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_object->radius = ft_atof(&line[i]);
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_object->shine = ft_atof(&line[i]);
	new_object->next = object;
	if (new_object->shine < 0 || new_object->radius < 0)
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (new_object);
}

t_object		*ft_add_cyl(t_object *object, char *line)
{
	t_object	*new_object;
	int			i;

	i = 0;
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		return (0);
	new_object->type = (line[0] == 'c' && line[1] == 'y') ? 3 : 4;
	new_object->center = ft_vec(i, line, new_object->center, 2);
	i = new_object->center.i;
	i = ft_next_space(i, line);
	new_object->n = ft_vec(i, line, new_object->n, 1);
	i = new_object->n.i;
	new_object->col = ft_color(i, line, new_object->col);
	i = new_object->col.i;
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_object->radius = ft_atof(&line[i]);
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_object->shine = ft_atof(&line[i]);
	new_object->next = object;
	if (new_object->shine < 0 || new_object->radius < 0)
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (new_object);
}