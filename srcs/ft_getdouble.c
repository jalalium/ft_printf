/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:41:51 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 20:46:09 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_getmantissa_dbl(double flo)
{
	char	*s;
	int		i;
	int		mantissa;

	s = pr_dbl(flo);
	i = 62;
	mantissa = 0;
	while (i > 51)
	{
		if (s[i] == '1')
		{
			mantissa += pow_two(i - 52);
		}
		i--;
	}
	return (mantissa - 1023);
}

void				mult_two_dbl(unsigned long long **o, int mantissa)
{
	unsigned long long	*sum;
	int					x;
	int					y;

	sum = *o;
	x = 0;
	while (x < mantissa)
	{
		y = 0;
		while (y < 200)
			sum[y++] *= 2;
		while (y > 0)
		{
			if (sum[y] >= 10)
			{
				sum[y - 1] += sum[y] / 10;
				sum[y] = sum[y] % 10;
			}
			y--;
		}
		x++;
	}
}

void				div_two_dbl(unsigned long long **o, int mantissa)
{
	int					x;
	int					y;
	unsigned long long	*sum;

	sum = *o;
	x = 0;
	while (x < -1 * mantissa)
	{
		y = 0;
		while (y < 199)
		{
			sum[y + 1] += 10 * (sum[y] % 2);
			sum[y] /= 2;
			y++;
		}
		sum[199] /= 2;
		carrying(&sum);
		x++;
	}
}

unsigned long long	*ft_getdouble(double flo)
{
	int					mantissa;
	unsigned long long	*out;

	out = ft_getfrac_dbl(flo);
	mantissa = ft_getmantissa_dbl(flo);
	if (mantissa >= 0)
		mult_two_dbl(&out, mantissa);
	if (mantissa < 0)
		div_two_dbl(&out, mantissa);
	return (out);
}
