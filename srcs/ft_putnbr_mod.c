/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:00:42 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 13:50:26 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_s_mod(long long nb, int *tab, int state)
{
	if (tab[10] == 'h' && tab[11] == 'h')
		return (ft_length_s_hh(nb, tab, state));
	if (tab[11] == 'h')
		return (ft_length_s_h(nb, tab, state));
	if (tab[10] == 'l' && tab[11] == 'l')
		return (ft_length_s_ll(nb, tab, state));
	if (tab[11] == 'l')
		return (ft_length_s_l(nb, tab, state));
	if (tab[11] == 'j')
		return (ft_length_s_j(nb, tab, state));
	if (tab[11] == 'z')
		return (ft_length_s_ll(nb, tab, state));
	return (ft_length_s(nb, tab, state));
}

int	ft_putnbr_s_mod(long long nb, int *tab)
{
	if (tab[10] == 'h' && tab[11] == 'h')
		return (ft_putnbr_s_hh(nb, tab));
	if (tab[11] == 'h')
		return (ft_putnbr_s_h(nb, tab));
	if (tab[10] == 'l' && tab[11] == 'l')
		return (ft_putnbr_s_ll(nb, tab));
	if (tab[11] == 'l')
		return (ft_putnbr_s_l(nb, tab));
	if (tab[11] == 'j')
		return (ft_putnbr_s_j(nb, tab));
	if (tab[11] == 'z')
		return (ft_putnbr_s_ll(nb, tab));
	return (ft_putnbr_s(nb, tab));
}
