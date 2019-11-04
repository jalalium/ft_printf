/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carrying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:02:18 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 20:06:30 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	carrying(unsigned long long **tum)
{
	unsigned long long	*sum;
	int					y;

	sum = *tum;
	y = 199;
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
