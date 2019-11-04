/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:31:49 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 22:36:19 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log_un_ll(unsigned long long n)
{
	return (n >= 1 ? 1 + ft_log_un_ll(n / 10) : 0);
}

int	ft_length_un_ll(unsigned long long n, int prec)
{
	int len;

	if (prec == 0 && n == 0)
		return (0);
	if (n == 0)
		return (prec == -1 ? 1 : prec);
	len = ft_log_un_ll(n);
	return (prec > len ? prec : len);
}

int	ft_putnbr_un_ll(unsigned long long n, int *tab)
{
	char	*pos;
	int		i;
	int		c;

	c = 0;
	pos = ft_strnew(ft_length_un_ll(n, tab[9]));
	i = (n == 0 ? 1 : ft_log_un_ll(n)) - 1;
	while (c < ft_length_un_ll(n, tab[9]) - i)
		pos[c++] = '0';
	while (i >= 0)
	{
		pos[c + i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	c = ft_strlen(pos);
	ft_putstr(pos);
	free(pos);
	return (c);
}
