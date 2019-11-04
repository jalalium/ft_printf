/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:06:31 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:30:28 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log_oct_l(unsigned long n)
{
	return (n >= 1 ? 1 + ft_log_oct_l(n / 8) : 0);
}

int	ft_sign_oct_l(unsigned long n, int *tab, int print)
{
	n = 2;
	if (tab[1] != 0)
	{
		if (print == 1)
			ft_putstr("0");
		return (1);
	}
	return (0);
}

int	ft_oct_length_l(unsigned long n, int *tab, int state)
{
	int len;
	int hash;

	len = 0;
	hash = 0;
	if (state == 1)
		hash += ft_sign_oct_l(n, tab, tab[2] != 0);
	if (tab[9] == 0 && n == 0 && tab[1] == 0)
		return (len + hash);
	if (n == 0)
		return (tab[9] == -1 ? 1 + hash : tab[9] + hash);
	len += ft_log_oct_l(n);
	return (tab[9] > len ? tab[9] + hash : len + hash);
}

int	ft_oct_l(unsigned long nb, int *tab)
{
	char	*hex;
	int		i;
	int		j;
	int		l;

	if (nb != 0 || (nb == 0 && tab[1] == 1 && tab[9] != -1))
		ft_sign_oct_l(nb, tab, tab[2] == 0);
	if (tab[9] == 0 && nb == 0)
		return (0);
	l = ft_oct_length_l(nb, tab, 0) - (tab[1] == 0 ? 0 : 1);
	hex = ft_strnew(l);
	i = 0;
	j = (nb == 0 ? 1 : ft_log_oct_l(nb));
	while (i < l - j)
		hex[i++] = '0';
	while (j > 0)
	{
		hex[i + j - 1] = nb % 8 + '0';
		nb /= 8;
		j--;
	}
	ft_putstr(hex);
	free(hex);
	return (l);
}
