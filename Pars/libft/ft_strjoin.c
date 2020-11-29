/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:37:29 by mstefani          #+#    #+#             */
/*   Updated: 2019/10/15 23:12:29 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_of_newline;
	char	*new_line;
	int		lens1;
	char	*l;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	l = (char*)s1;
	size_of_newline = ft_strlen(s1) + ft_strlen(s2);
	lens1 = ft_strlen(s1);
	new_line = ft_memalloc(size_of_newline + 1);
	if (!new_line)
		return (NULL);
	ft_strlcat(new_line, s1, lens1 + 1);
	ft_strlcat(new_line, s2, size_of_newline + 1);
	free(l);
	return (new_line);
}
