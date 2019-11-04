/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:19:19 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 23:56:46 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_space_right(int *tab, int len)
{
	int count;
	int e;

	count = tab[7] - len;
	e = count;
	if (tab[4] == 0 || tab[6] == 0 || count <= 0)
		return (0);
	while (count)
	{
		ft_putstr(" ");
		count--;
	}
	return (e);
}
