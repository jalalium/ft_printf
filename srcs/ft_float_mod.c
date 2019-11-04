/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:09:54 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 19:46:45 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenfloat_mod(long double nb, int *tab)
{
	if (tab[11] == 'L')
		return (ft_lenldbl(nb, tab[9]));
	return (ft_lendbl(nb, tab[9]));
}

int	ft_putfloat_mod(long double nb, int *tab)
{
	if (tab[11] == 'L')
		return (ft_putldbl(nb, tab[9]));
	return (ft_putdbl(nb, tab[9]));
}
