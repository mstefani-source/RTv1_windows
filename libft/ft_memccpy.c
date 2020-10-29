/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:13:44 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/30 20:38:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*idst;
	unsigned char	*isrc;
	unsigned char	ch;
	size_t			i;

	idst = (unsigned char*)dst;
	isrc = (unsigned char*)src;
	ch = (unsigned char)c;
	i = 0;
	while (i - n)
	{
		*idst = isrc[i];
		if (isrc[i] == ch)
			return (++idst);
		i++;
		idst++;
	}
	return (NULL);
}
