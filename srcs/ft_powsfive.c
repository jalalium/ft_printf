/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powsfive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:54:02 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 21:19:10 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_carryover(int *t[200])
{
	int	*sum;
	int	j;

	sum = *t;
	j = 199;
	while (j >= 0)
	{
		if (sum[j] >= 10)
		{
			sum[j - 1] += sum[j] / 10;
			sum[j] = sum[j] % 10;
		}
		j--;
	}
}

void				ft_gen_pows(unsigned long long *kl[200], int *sum, int t)
{
	int					k;
	int					j;
	int					x;
	unsigned long long	*tab;

	tab = *kl;
	k = 0;
	x = 0;
	while (sum[x++] == 0)
		k++;
	j = t - 200 + k + 1;
	while (x < j)
		tab[x++] = 0;
	x = 0;
	while (x < 200 - k)
	{
		tab[j + x] = sum[k + x];
		x++;
	}
}

void				mult_five(int *s[200])
{
	int	*sum;
	int	i;

	sum = *s;
	i = 199;
	while (i >= 0)
	{
		sum[i] *= 5;
		i--;
	}
}

unsigned long long	**powsfive(void)
{
	unsigned long long	**out;
	int					*sum;
	int					t;

	t = 0;
	out = (unsigned long long**)malloc(sizeof(unsigned long long*) * 90);
	sum = (int*)malloc(sizeof(int) * 200);
	while (t < 200)
		sum[t++] = 0;
	sum[199] = 1;
	t = 0;
	while (t < 90)
	{
		mult_five(&sum);
		ft_carryover(&sum);
		out[t] = (unsigned long long*)malloc(sizeof(unsigned long long) * 200);
		ft_gen_pows(&out[t], sum, t);
		t++;
	}
	return (out);
}
