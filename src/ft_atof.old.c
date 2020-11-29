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

#include "stdio.h"
#include "limits.h"
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
	if (nptr[i] == '-')
		k = -1;
	nr = ft_atoi(&nptr[i]);
	while (ft_isdigit(nptr[i]) || (nptr[i] == '-'))
		i++;
	if (nptr[i++] == '.')
	{
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
