/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:38:27 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 19:28:07 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pr_dbl(double x)
{
	int		*y;
	int		i;
	char	*s;

	s = (char*)malloc(sizeof(char) * 64);
	y = (int*)&x;
	i = 63;
	while (i >= 0)
	{
		if ((y[i / 32] >> i) & 1)
			s[i] = '1';
		else
			s[i] = '0';
		i--;
	}
	s[64] = '\0';
	return (s);
}