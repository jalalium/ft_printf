/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:00:42 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:09:59 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_un_mod(unsigned long long nb, int *tab)
{
	if (tab[10] == 'h' && tab[11] == 'h')
		return (ft_length_un_hh(nb, tab[9]));
	if (tab[11] == 'h')
		return (ft_length_un_h(nb, tab[9]));
	if (tab[10] == 'l' && tab[11] == 'l')
		return (ft_length_un_ll(nb, tab[9]));
	if (tab[11] == 'l')
		return (ft_length_un_l(nb, tab[9]));
	if (tab[11] == 'j')
		return (ft_length_un_j(nb, tab[9]));
	if (tab[11] == 'z')
		return (ft_length_un_ll(nb, tab[9]));
	return (ft_length_un(nb, tab[9]));
}

int	ft_putnbr_un_mod(unsigned long long nb, int *tab)
{
	if (tab[10] == 'h' && tab[11] == 'h')
		return (ft_putnbr_un_hh(nb, tab));
	if (tab[11] == 'h')
		return (ft_putnbr_un_h(nb, tab));
	if (tab[10] == 'l' && tab[11] == 'l')
		return (ft_putnbr_un_ll(nb, tab));
	if (tab[11] == 'l')
		return (ft_putnbr_un_l(nb, tab));
	if (tab[11] == 'j')
		return (ft_putnbr_un_j(nb, tab));
	if (tab[11] == 'z')
		return (ft_putnbr_un_ll(nb, tab));
	return (ft_putnbr_un(nb, tab));
}
