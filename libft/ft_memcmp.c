/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:43:02 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 20:34:36 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	if (n == 0)
		return (0);
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (us1[i] == us2[i] && i < n - 1)
		i++;
	return ((int)(us1[i] - us2[i]));
}
