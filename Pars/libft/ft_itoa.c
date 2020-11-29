/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:23 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/26 20:59:25 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	char	*fin;

	len = ft_leni(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	res[len--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n / 1 == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	fin = res;
	free(res);
	return (fin);
}
