/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llondoub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:55:43 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 20:20:04 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding_ldbl(unsigned long long **tab, int i)
{
	unsigned long long	*in;
	int					j;

	in = *tab;
	if (in[i] > 5)
		in[i - 1]++;
	j = 9999;
	while (j >= 0)
	{
		if (in[j] >= 10)
		{
			in[j - 1] += in[j] / 10;
			in[j] = in[j] % 10;
		}
		j--;
	}
}

int		print_sign_ldbl(long double num, int print)
{
	if (pr_ldbl(num)[79] == '1')
	{
		if (print == 1)
			ft_putchar('-');
		return (1);
	}
	return (0);
}

int		ft_special_lcases(long double num, int print)
{
	char	**bound_case;

	bound_case = inport_spec_lstrings();
	if (ft_strcmp(pr_ldbl(num), bound_case[0]) == 0)
	{
		if (print == 1)
			ft_putstr("+inf");
		return (4);
	}
	else if (ft_strcmp(pr_ldbl(num), bound_case[1]) == 0)
	{
		if (print == 1)
			ft_putstr("-inf");
		return (4);
	}
	else if (ft_strcmp(pr_ldbl(num), bound_case[2]) == 0)
	{
		if (print == 1)
			ft_putstr("NaN");
		return (3);
	}
	else
		return (0);
}

int		ft_lenldbl(long double num, int prec)
{
	int					i;
	unsigned long long	*in;
	int					out;

	i = 1;
	out = 0;
	if (ft_special_lcases(num, 0) != 0)
		return (ft_special_lcases(num, 0));
	in = ft_getldouble(num);
	if (prec == -1)
		prec = 6;
	out += print_sign_ldbl(num, 0);
	while (in[i] == 0 && i < 4999)
		i++;
	while (i++ < 5000)
		out++;
	if (prec > 0)
		out++;
	while (prec-- > 0)
		out++;
	return (out);
}

int		ft_putldbl(long double num, int prec)
{
	int					i;
	unsigned long long	*in;

	i = 1;
	if (ft_special_lcases(num, 1) != 0)
		return (0);
	in = ft_getldouble(num);
	prec = (prec == -1 ? 6 : prec);
	rounding_ldbl(&in, 5000 + prec);
	print_sign_ldbl(num, 1);
	while (in[i] == 0 && i < 4999)
		i++;
	while (i < 5000)
		ft_putnbr((int)(in[i++]));
	if (prec > 0)
		ft_putchar('.');
	while (prec > 0)
	{
		ft_putnbr((int)(in[i++]));
		prec--;
	}
	return (0);
}
