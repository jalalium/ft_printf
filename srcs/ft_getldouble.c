/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:50:53 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 20:47:55 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				carrying_ldbl(unsigned long long **tum)
{
	unsigned long long	*sum;
	int					y;

	sum = *tum;
	y = 9999;
	while (y > 0)
	{
		if (sum[y] >= 10)
		{
			sum[y - 1] += sum[y] / 10;
			sum[y] = sum[y] % 10;
		}
		y--;
	}
}

int					ft_getmantissa_ldbl(long double flo)
{
	char	*s;
	int		i;
	int		mantissa;

	s = pr_ldbl(flo);
	i = 78;
	mantissa = 0;
	while (i > 63)
	{
		if (s[i] == '1')
		{
			mantissa += pow_two(i - 64);
		}
		i--;
	}
	return (mantissa - 16383);
}

void				mult_two_ldbl(unsigned long long **o, int mantissa)
{
	unsigned long long	*sum;
	int					x;
	int					y;

	sum = *o;
	x = 0;
	while (x < mantissa)
	{
		y = 0;
		while (y < 10000)
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

void				div_two_ldbl(unsigned long long **o, int mantissa)
{
	int					x;
	int					y;
	unsigned long long	*sum;

	sum = *o;
	x = 0;
	while (x < -1 * mantissa)
	{
		y = 0;
		while (y < 9999)
		{
			sum[y + 1] += 10 * (sum[y] % 2);
			sum[y] /= 2;
			y++;
		}
		sum[9999] /= 2;
		carrying_ldbl(&sum);
		x++;
	}
}

unsigned long long	*ft_getldouble(long double flo)
{
	int					mantissa;
	unsigned long long	*out;

	out = ft_getfrac_ldbl(flo);
	if (out[0] == 6)
		return (out);
	mantissa = ft_getmantissa_ldbl(flo);
	if (out[0] == 5)
		mantissa -= 63;
	if (mantissa >= 0)
		mult_two_ldbl(&out, mantissa);
	if (mantissa < 0)
		div_two_ldbl(&out, mantissa);
	return (out);
}
