/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:19:48 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:14:35 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*sp;

	ch = (char)c;
	sp = (char*)s;
	while (*sp != '\0' && *sp != ch)
		sp++;
	if (ch == '\0')
		return (sp);
	if (*sp == '\0')
		return (NULL);
	return (sp);
}
