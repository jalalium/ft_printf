/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:08:33 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 22:14:53 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_oct_length_mod(unsigned long long nb, int *tab, int state)
{
	if (tab[10] == 'h' && tab[11] == 'h')
		return (ft_oct_length_hh(nb, tab, state));
	if (tab[11] == 'h')
		return (ft_oct_length_h(nb, tab, state));
	if (tab[10] == 'l' && tab[11] == 'l')
		return (ft_oct_length_ll(nb, tab, state));
	if (tab[11] == 'l')
		return (ft_oct_length_l(nb, tab, state));
	if (tab[11] == 'j')
		return (ft_oct_length_j(nb, tab, state));
	if (tab[11] == 'z')
		return (ft_oct_length_ll(nb, tab, state));
	return (ft_oct_length_u(nb, tab, state));
}

int	ft_oct_mod(unsigned long long nb, int *tab)
{
	if (tab[12] == 'p')
		return (ft_oct_l(nb, tab));
	if (tab[10] == 'h' && tab[11] == 'h')
		return (ft_oct_hh(nb, tab));
	if (tab[11] == 'h')
		return (ft_oct_h(nb, tab));
	if ((tab[10] == 'l' && tab[11] == 'l') || tab[11] == 'z')
		return (ft_oct_ll(nb, tab));
	if (tab[11] == 'l')
		return (ft_oct_l(nb, tab));
	if (tab[11] == 'j')
		return (ft_oct_j(nb, tab));
	return (ft_oct_u(nb, tab));
}
