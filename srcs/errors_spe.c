/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:19:58 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 13:15:21 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	errors_det(int *tab, int state)
{
	if (tab[0] != 0)
	{
		if (state == 1)
			ft_putchar('%');
		return (1);
	}
	if (count_skip(tab) == 0)
		return (0);
	return (-1);
}

int	spec_cases(int conv)
{
	if (conv < 0)
		return (5);
	if (conv == 0)
		return (4);
	return (10);
}
