/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdoub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:54:57 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 20:22:51 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding_dbl(unsigned long long **tab, int i)
{
	unsigned long long	*in;
	int					j;

	in = *tab;
	if (in[i] > 5)
		in[i - 1]++;
	j = 199;
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

int		print_sign_dbl(double num, int print)
{
	if (pr_dbl(num)[63] == '1')
	{
		if (print == 1)
			ft_putchar('-');
		return (1);
	}
	return (0);
}

int		ft_special_cases(double num, int print)
{
	char	**bound_case;

	bound_case = inport_spec_strings();
	if (ft_strcmp(pr_dbl(num), bound_case[0]) == 0)
	{
		if (print == 1)
			ft_putstr("+inf");
		return (4);
	}
	else if (ft_strcmp(pr_dbl(num), bound_case[1]) == 0)
	{
		if (print == 1)
			ft_putstr("-inf");
		return (4);
	}
	else if (ft_strcmp(pr_dbl(num), bound_case[2]) == 0)
	{
		if (print == 1)
			ft_putstr("NaN");
		return (3);
	}
	else
		return (0);
}

int		ft_lendbl(double num, int prec)
{
	int					i;
	unsigned long long	*in;
	int					out;

	i = 1;
	out = 0;
	if (ft_special_cases(num, 0) != 0)
		return (ft_special_cases(num, 0));
	in = ft_getdouble(num);
	if (prec == -1)
		prec = 6;
	out += print_sign_dbl(num, 0);
	while (in[i] == 0 && i < 99)
		i++;
	while (i++ < 100)
		out++;
	if (prec > 0)
		out++;
	while (prec-- > 0)
		out++;
	return (out);
}

int		ft_putdbl(double num, int prec)
{
	int					i;
	unsigned long long	*in;

	i = 1;
	if (ft_special_cases(num, 1) != 0)
		return (0);
	in = ft_getdouble(num);
	prec = (prec == -1 ? 6 : prec);
	rounding_dbl(&in, 100 + prec);
	print_sign_dbl(num, 1);
	while (in[i] == 0 && i < 99)
		i++;
	while (i < 100)
		ft_putnbr((int)(in[i++]));
	if (prec != 0)
		ft_putchar('.');
	while (prec > 0)
	{
		ft_putnbr((int)(in[i++]));
		prec--;
	}
	return (0);
}
