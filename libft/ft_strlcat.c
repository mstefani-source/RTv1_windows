/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:44:14 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:16:56 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (srclen + size);
	j = 0;
	size--;
	while (src[j] && j < (size - dstlen))
	{
		dst[j + dstlen] = src[j];
		j++;
	}
	dst[j + dstlen] = '\0';
	return (srclen + dstlen);
}
