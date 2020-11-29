/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:08:22 by skale             #+#    #+#             */
/*   Updated: 2020/11/14 11:41:19 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

double ft_atof (const char *nptr)
{
	int				i;
	double			nr;
	int				k;
	double				s;
	int z;

	i = 0;
	nr = 0;
	k = 1;
	z = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] >= 'a' && nptr[i] <= 'z')|| (nptr[i] >= 'A' && nptr[i] <= 'Z'))
		i++;
	if (nptr[i] == '-')
		k = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		s = nptr[i] - '0';
		if (k == 1 && (nr > LONG_MAX / 10 || (nr == LONG_MAX / 10 && s > 7)))
			return (-1);
		if (k == -1 && (nr > LONG_MAX / 10 || (nr == LONG_MAX / 10 && s > 8)))
			return (0);
		nr = nr * 10 + s;
		i++;
	}
	if (nptr[i] == '.')
	{
		i++;
		while ((nptr[i] >= '0') && (nptr[i] <= '9'))
		{
			z = z * 10;
			s = nptr[i] - '0';
			nr = s / z + nr;
			i++;
		}
	}
	return (nr * k);
}
