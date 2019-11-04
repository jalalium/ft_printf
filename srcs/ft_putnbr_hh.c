/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:02:03 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 22:12:52 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log_s_hh(unsigned char n)
{
	return (n >= 1 ? 1 + ft_log_s_hh(n / 10) : 0);
}

int	ft_sign_hh(char n, int *tab, int print)
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

int	ft_length_s_hh(char n, int *tab, int state)
{
	int				len;
	int				sign;
	unsigned char	m;

	len = 0;
	sign = 0;
	m = n;
	if (state == 1)
		sign += ft_sign_hh(n, tab, (tab[2] != 0 && tab[9] != -1));
	if (tab[9] == 0 && n == 0)
		return (len + sign);
	if (n == 0)
		return (tab[9] == -1 ? 1 + sign : tab[9] + sign);
	if (n < 0)
		m = -n;
	len = ft_log_s_hh(m);
	return (tab[9] > len ? tab[9] + sign : len + sign);
}

int	ft_putnbr_s_hh(char n, int *tab)
{
	char			*pos;
	int				i;
	int				t;
	int				c;
	unsigned char	m;

	c = 0;
	t = ft_length_s_hh(n, tab, 0);
	m = (n > 0 ? n : -n);
	pos = ft_strnew(t);
	ft_sign_hh(n, tab, (tab[2] == 0 || tab[9] == -1));
	i = (n == 0 ? 1 : ft_log_s_hh(m)) - 1;
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
