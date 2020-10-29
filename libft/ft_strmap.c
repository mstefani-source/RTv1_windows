/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:09:22 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:17:27 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*newstring;

	i = 0;
	if ((s == 0) || (*f) == 0)
		return (NULL);
	size = ft_strlen(s);
	newstring = (char*)malloc(sizeof(char) * (size + 1));
	if (!newstring)
		return (NULL);
	ft_bzero(newstring, size + 1);
	while (s[i])
	{
		newstring[i] = (*f)(s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
