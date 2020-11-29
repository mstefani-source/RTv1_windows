/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:31:10 by mstefani          #+#    #+#             */
/*   Updated: 2019/10/16 14:46:33 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_and_free(char **s1, char const *s2)
{
	int		size_of_newline;
	char	*new_line;
	int		lens1;
	int		lens2;
	char	*l;

	if (*s1 == 0 || s2 == 0)
		return (NULL);
	l = *s1;
	lens1 = ft_strlen(*s1);
	lens2 = ft_strlen(s2);
	size_of_newline = lens1 + lens2;
	new_line = ft_memalloc(size_of_newline + 1);
	if (!new_line)
		return (NULL);
	ft_strlcat(new_line, *s1, lens1 + 1);
	ft_strlcat(new_line, s2, size_of_newline + 1);
	free(l);
	*s1 = new_line;
	return (*s1);
}
