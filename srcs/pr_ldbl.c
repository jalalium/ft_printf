/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_ldbl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:05:12 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 19:19:21 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pr_ldbl(long double x)
{
	int		*y;
	int		i;
	char	*s;

	s = (char*)malloc(sizeof(char) * 80);
	y = (int*)&x;
	i = 79;
	while (i >= 0)
	{
		if ((y[i / 32] >> i) & 1)
			s[i] = '1';
		else
			s[i] = '0';
		i--;
	}
	return (s);
}