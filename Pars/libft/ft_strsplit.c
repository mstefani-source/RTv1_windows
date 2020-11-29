/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:03:21 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/23 15:51:06 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_num(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == '\0')
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_len(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	**ft_tabledel(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word_num;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	word_num = ft_word_num(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (word_num + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_num)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		tab[i] = ft_strsub(s, j, ft_len(s + j, c));
		if (tab[i] == NULL)
			return (ft_tabledel(tab, i));
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
