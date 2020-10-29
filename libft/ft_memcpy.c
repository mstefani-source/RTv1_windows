/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:24:50 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:23:25 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*idst;
	unsigned char	*isrc;
	size_t			i;

	i = 0;
	idst = (unsigned char*)dst;
	isrc = (unsigned char*)src;
	if (idst == ((void *)0) && isrc == ((void *)0))
		return (0);
	while (n - i)
	{
		idst[i] = isrc[i];
		i++;
	}
	return (dst);
}
