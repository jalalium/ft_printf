/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:16:44 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:42:50 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adjust_prec(int **t)
{
	int *tab;

	tab = *t;
	if (tab[9] < 0 && tab[8] != 0)
	{
		tab[9] = -1;
		tab[8] = 0;
	}
}

void	ft_adjust(int **t)
{
	int *tab;

	tab = *t;
	adjust_prec(t);
	if (tab[12] == 'C')
	{
		tab[10] = 0;
		tab[11] = 0;
	}
	if (tab[7] < 0)
	{
		tab[7] = -1 * tab[7];
		tab[4] = 1;
	}
}
