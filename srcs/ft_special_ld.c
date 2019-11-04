/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_ld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:09:47 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:15:13 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nothingness_ldbl(char *s, unsigned long long **t)
{
	int					i;
	unsigned long long	*sum;

	i = 79;
	sum = *t;
	while (s[i] == '0')
		i--;
	if (i == 64)
		sum[0] = 6;
}

void	geometric_sum_ldbl(char *s, unsigned long long **t)
{
	int					i;
	unsigned long long	*sum;

	i = 62;
	sum = *t;
	while (s[i] == '1')
		i--;
	if (i == -1)
	{
		sum[4998] = 1844674407370955161;
		carryfracldbl(&sum, 4998);
		sum[4999] = 5;
		sum[0] = 5;
	}
	else
		sum[4999] = (s[63] == '1' ? 1 : 0);
	return ;
}
