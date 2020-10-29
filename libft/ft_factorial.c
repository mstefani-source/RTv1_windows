/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:14:25 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/23 16:22:08 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	int next;

	next = nb - 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	nb = nb * ft_factorial(next);
	return (nb);
}
