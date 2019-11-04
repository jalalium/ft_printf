/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:11:20 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 22:11:47 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log_s_h(unsigned short n)
{
	return (n >= 1 ? 1 + ft_log_s_h(n / 10) : 0);
}

int	ft_sign_h(short n, int *tab, int print)
{
	if (n < 0)
	{
		if (print == 1)
			ft_putchar('-');
		return (1);
	}
	if ((tab[3] != 0 || tab[5] != 0) && n >= 0)
	{
		if (tab[3] != 0)
		{
			if (print == 1)
				ft_putchar('+');
		}
		else
		{
			if (print == 1)
				ft_putchar(' ');
		}
		return (1);
	}
	return (0);
}

int	ft_length_s_h(short n, int *tab, int state)
{
	int				len;
	int				sign;
	unsigned short	m;

	len = 0;
	sign = 0;
	m = n;
	if (state == 1)
		sign += ft_sign_h(n, tab, (tab[2] != 0 && tab[9] != -1));
	if (tab[9] == 0 && n == 0)
		return (len + sign);
	if (n == 0)
		return (tab[9] == -1 ? 1 + sign : tab[9] + sign);
	if (n < 0)
		m = -n;
	len = ft_log_s_h(m);
	return (tab[9] > len ? tab[9] + sign : len + sign);
}

int	ft_putnbr_s_h(short n, int *tab)
{
	char			*pos;
	int				i;
	int				t;
	int				c;
	unsigned short	m;

	c = 0;
	t = ft_length_s_h(n, tab, 0);
	m = (n > 0 ? n : -n);
	pos = ft_strnew(t);
	ft_sign_h(n, tab, (tab[2] == 0 || tab[9] == -1));
	i = (n == 0 ? 1 : ft_log_s_h(m)) - 1;
	while (c < t - i)
		pos[c++] = '0';
	while (i >= 0)
	{
		pos[c + i - 1] = m % 10 + '0';
		m /= 10;
		i--;
	}
	ft_putstr(pos);
	free(pos);
	return (t);
}
