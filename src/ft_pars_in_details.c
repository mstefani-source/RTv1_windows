/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_in_details.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:37 by skale             #+#    #+#             */
/*   Updated: 2020/12/01 18:20:24 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

int		ft_next_digit(int i, char *line)
{
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	return (i);
}

int		ft_next_space(int i, char *line)
{
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	return (i);
}

t_color	ft_color(int i, char *line, t_color color)
{
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	color.r = ft_atoi(&line[i]);
	i = ft_next_space(i, line) + 1;
	color.g = ft_atoi(&line[i]);
	i = ft_next_space(i, line) + 1;
	color.b = ft_atoi(&line[i]);
	color.i = i;
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 \
			|| color.b < 0 || color.b > 255)
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (color);
}

t_vec	ft_vec(int i, char *line, t_vec vec, int type)
{
	i = ft_next_digit(i, line);
	vec.x = ft_atof(&line[i]);
	i = ft_next_space(i, line) + 1;
	vec.y = ft_atof(&line[i]);
	i = ft_next_space(i, line) + 1;
	vec.z = ft_atof(&line[i]);
	vec.i = i;
	if ((type == 1) && (vec.x > 1 || vec.x < -1 || vec.y > 1 || \
				vec.y < -1 || vec.z > 1 || vec.z < -1))
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (vec);
}

t_light	*ft_add_light(t_light *light, char *line)
{
	t_light	*new_light;
	int		i;

	i = 0;
	if(!(new_light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	i = ft_next_digit(i, line);
	new_light->position.x = ft_atof(&line[i]);
	i = ft_next_space(i, line);
	new_light->position.y = ft_atof(&line[++i]);
	i = ft_next_space(i, line);
	new_light->position.z = ft_atof(&line[++i]);
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_light->intensity = ft_atof(&line[i]);
	i = ft_next_space(i, line);
	i = ft_next_digit(i, line);
	new_light->type = ft_atoi(&line[i]);
	new_light->next = light;
	if ((new_light->type != 1 && new_light->type != 2) || \
			new_light->intensity < 0 || new_light->intensity > 1)
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (new_light);
}