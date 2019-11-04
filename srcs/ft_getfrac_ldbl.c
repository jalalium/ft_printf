/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfrac_ldbl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:49:16 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 15:01:23 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				su(char *s, unsigned long long **p, unsigned long long **f)
{
	int					x;
	int					y;
	unsigned long long	*sum;

	sum = *p;
	x = 0;
	while (x < 63)
	{
		y = 0;
		if (s[62 - x] == '1')
		{
			while (y < 5000)
			{
				sum[5000 + y] += f[x][y];
				y++;
			}
			carryfracldbl(&sum, 9999);
		}
		x++;
	}
}

void				initialize(unsigned long long **tab)
{
	int					y;
	unsigned long long	*sum;

	sum = *tab;
	y = 0;
	while (y < 10000)
		sum[y++] = 0;
}

unsigned long long	*add_frac_ldbl(char *s, int x, unsigned long long **frac)
{
	unsigned long long	*sum;
	int					y;

	sum = (unsigned long long*)malloc(sizeof(unsigned long long) * 10000);
	nothingness_ldbl(s, &sum);
	geometric_sum_ldbl(s, &sum);
	if (sum[0] == 5 || sum[0] == 6)
		return (sum);
	sum[4999] = (s[63] == '1' ? 1 : 0);
	while (x < 63)
	{
		y = 0;
		if (s[62 - x] == '1')
		{
			while (y < 5000)
			{
				sum[5000 + y] += frac[x][y];
				y++;
			}
			carryfracldbl(&sum, 9999);
		}
		x++;
	}
	return (sum);
}

unsigned long long	*ft_getfrac_ldbl(long double flo)
{
	char				*s;
	unsigned long long	**frac;

	s = pr_ldbl(flo);
	frac = powsfive();
	return (add_frac_ldbl(s, 0, frac));
}
