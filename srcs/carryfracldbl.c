/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carryfracldbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:13:39 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:14:14 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				carryfracldbl(unsigned long long **t, int j)
{
	unsigned long long	*sum;

	sum = *t;
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
