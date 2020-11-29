/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:42:09 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:17:38 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstring;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (s == 0 || (*f) == 0)
		return (NULL);
	size = (unsigned int)ft_strlen(s);
	newstring = (char*)malloc(sizeof(char) * (size + 1));
	if (!newstring)
		return (NULL);
	while (s[i])
	{
		newstring[i] = (*f)(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
