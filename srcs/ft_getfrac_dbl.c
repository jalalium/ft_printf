/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfrac_dbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:40:02 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 20:06:28 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	*add_frac_dbl(char *s, int x, unsigned long long **frac)
{
	unsigned long long	*sum;
	int					y;

	sum = (unsigned long long*)malloc(sizeof(unsigned long long) * 200);
	y = 0;
	while (y < 200)
		sum[y++] = 0;
	sum[99] = 1;
	while (x < 52)
	{
		y = 0;
		if (s[51 - x] == '1')
		{
			while (y < 100)
			{
				sum[100 + y] += frac[x][y];
				y++;
			}
			carrying(&sum);
		}
		x++;
	}
	return (sum);
}

unsigned long long	*ft_getfrac_dbl(double flo)
{
	char				*s;
	unsigned long long	**frac;

	s = pr_dbl(flo);
	frac = powsfive();
	return (add_frac_dbl(s, 0, frac));
}
