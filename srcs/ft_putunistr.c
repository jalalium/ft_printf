/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:08:22 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/02 19:52:22 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenunistr(char *str, int *p)
{
	int *tab;
	int i;
	int out;
	int pout;

	i = 0;
	pout = 0;
	tab = (int*)str;
	out = ft_lenunicode(tab[0]);
	while (tab[i] != 0 && (out <= p[9] || p[9] == -1))
	{
		pout += ft_lenunicode(tab[i]);
		out += ft_lenunicode(tab[i + 1]);
		i++;
	}
	return (pout);
}

int	ft_putunistr(char *str, int *p)
{
	int *tab;
	int i;
	int k;

	i = 0;
	tab = (int*)str;
	k = ft_lenunicode(tab[0]);
	while (tab[i] != 0 && (k <= p[9] || p[9] == -1))
	{
		ft_putunicode(tab[i]);
		k += ft_lenunicode(tab[i + 1]);
		i++;
	}
	return (1);
}
