/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:00:59 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 20:40:07 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((*ps1 == *ps2) && (i < n - 1) && *ps1 != '\0')
	{
		ps1++;
		ps2++;
		i++;
	}
	return (*ps1 - *ps2);
}
