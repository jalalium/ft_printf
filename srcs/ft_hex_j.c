/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:46:02 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 21:57:54 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log_hex_j(uintmax_t n)
{
	return (n >= 1 ? 1 + ft_log_hex_j(n / 16) : 0);
}

int	ft_sign_hex_j(uintmax_t n, int *tab, int print)
{
	if ((tab[1] != 0 && n != 0) || tab[12] == 'p')
	{
		if (tab[12] == 'X')
		{
			if (print == 1)
				ft_putstr("0X");
		}
		else
		{
			if (print == 1)
				ft_putstr("0x");
		}
		return (2);
	}
	return (0);
}

int	ft_hex_length_j(uintmax_t n, int *tab, int state)
{
	int len;
	int hash;

	len = 0;
	hash = 0;
	if (state == 1)
		hash += ft_sign_hex_j(n, tab, tab[2] != 0);
	if (tab[9] == 0 && n == 0)
		return (len);
	if (n == 0)
		return (tab[9] == -1 ? 1 : tab[9]);
	len += ft_log_hex_j(n);
	return (tab[9] > len ? tab[9] + hash : len + hash);
}

int	ft_hex_j(uintmax_t nb, int *tab)
{
	char	*hex;
	int		i;
	int		j;
	int		l;
	int		c;

	l = ft_hex_length_j(nb, tab, 0);
	hex = ft_strnew(l);
	ft_sign_hex_j(nb, tab, tab[2] == 0);
	c = (tab[12] == 'X' ? 'A' : 'a');
	i = 0;
	j = (nb == 0 ? 1 : ft_log_hex_j(nb)) - 1;
	while (i < l - j)
		hex[i++] = '0';
	while (j >= 0)
	{
		hex[i + j - 1] = (nb % 16 > 9 ? nb % 16 - 10 + c : nb % 16 + '0');
		nb /= 16;
		j--;
	}
	ft_putstr(hex);
	free(hex);
	return (l);
}
