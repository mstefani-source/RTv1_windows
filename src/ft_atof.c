/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:20:47 by skale             #+#    #+#             */
/*   Updated: 2020/12/01 19:27:30 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

double			ft_atof(const char *nptr)
{
	int			i;
	double		nr;
	double		s;
	int			z;
	int			k;

	i = 0;
	nr = 0;
	z = 1;
	nr = ft_atoi(&nptr[i]);
	k = (nptr[i] == '-') ? -1 : 1;
	nr = nr * k;
	while ((nptr[i] >= '0' && nptr[i] <= '9') || (nptr[i] == '-'))
		i++;
	(nptr[i] == '.') ? i++ : 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		z = z * 10;
		s = nptr[i++] - '0';
		nr = s / z + nr;
	}
	return (k * nr);
}

t_viewport		*ft_set_portale(double d, double vw, double vh)
{
	t_viewport	*portale;

	portale = (t_viewport*)malloc(sizeof(t_viewport));
	portale->d = d;
	portale->vw = vw;
	portale->vh = vh;
	return (portale);
}
