/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:22:14 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:12:10 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ddst;
	char	*dsrc;

	if ((dst == src) || (len == 0))
		return (dst);
	ddst = (char*)dst;
	dsrc = (char*)src;
	if (ddst > dsrc)
	{
		ddst = ddst + len - 1;
		dsrc = dsrc + len - 1;
		while (len)
		{
			*ddst-- = *dsrc--;
			len--;
		}
		return (dst);
	}
	while (len--)
		*ddst++ = *dsrc++;
	return (dst);
}
