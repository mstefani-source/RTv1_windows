/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:30:44 by skale             #+#    #+#             */
/*   Updated: 2020/12/03 20:54:40 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

t_scene		*ft_init_rtv(void)
{
	t_scene	*res;

	if (!(res = (t_scene*)malloc(sizeof(t_scene))))
		return (0);
	if (!(res->objects = (t_object*)malloc(sizeof(t_object))))
		return (0);
	res->objects->next = NULL;
	if (!(res->cam_pos = (t_vec *)malloc(sizeof(t_vec))))
		return (0);
	if (!(res->light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	res->light->next = NULL;
	res->ht = 0;
	res->wd = 0;
	return (res);
}

int			ft_prov(double x, double y)
{
	if (x < 0 || y < 0)
	{
		write(1, "Error data\n", 11);
		exit(0);
	}
	return (0);
}

t_scene		*ft_build(t_scene *res, char *line)
{
	int		i;

	i = 0;
	if (line[i] == 'R')
	{
		i = ft_next_digit(i, line);
		res->wd = ft_atof(&line[i]);
		i = ft_next_space(i, line);
		i = ft_next_digit(i, line);
		res->ht = ft_atof(&line[i]);
		ft_prov(res->ht, res->wd);
	}
	if (line[0] == 'L')
		res->light = ft_add_light(res->light, line);
	if (line[0] == 'p' && line[1] == 'l')
		res->objects = ft_add_plane(res->objects, line);
	if (line[0] == 's' && line[1] == 'p')
		res->objects = ft_add_sphere(res->objects, line);
	if (line[0] == 'c' && (line[1] == 'y' || line[1] == 'o'))
		res->objects = ft_add_cyl(res->objects, line);
	if (line[0] == 'C')
		*res->cam_pos = ft_vec(i, line, *res->cam_pos, 2);
	if (line[0] == 'A')
		res->angle = ft_vec(i, line, res->angle, 3);
	return (res);
}

int			ft_provsym(char k)
{
	if (ft_isdigit(k) || (k == '-') || (k == ' ') || (k == '.') || \
			(k == ',') || (k == '\n') || ft_isalpha(k))
		return (1);
	else
	{
		write(1, "Error data\n", 11);
		return (0);
	}
}

t_scene		*ft_parce_scene(char *file)
{
	int		fd;
	char	*line;
	int		i;
	t_scene	*res;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	res = ft_init_rtv();
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i])
			ft_provsym(line[i++]);
		ft_build(res, line);
		free(line);
	}
	res->portale = ft_set_portale(1.0 + res->cam_pos->z, 1.0, \
			((res->ht) / (res->wd)) - 0.24);
	return (res);
}
