/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:17:46 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 19:38:40 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*letters(void)
{
	int *in;

	in = (int*)malloc(sizeof(int) * 14);
	in[0] = 115;
	in[1] = 99;
	in[2] = 112;
	in[3] = 120;
	in[4] = 88;
	in[5] = 111;
	in[6] = 100;
	in[7] = 68;
	in[8] = 105;
	in[9] = 117;
	in[10] = 102;
	in[11] = 67;
	in[12] = 83;
	in[13] = 98;
	return (in);
}

int	*mapping(void)
{
	int *in;

	in = (int*)malloc(sizeof(int) * 14);
	in[0] = 0;
	in[1] = 1;
	in[2] = 2;
	in[3] = 2;
	in[4] = 2;
	in[5] = 3;
	in[6] = 4;
	in[7] = 4;
	in[8] = 4;
	in[9] = 5;
	in[10] = 6;
	in[11] = 7;
	in[12] = 8;
	in[13] = 9;
	return (in);
}

int	conv_data(int c)
{
	int *in;
	int *out;
	int i;

	i = 0;
	in = letters();
	out = mapping();
	while (in[i] != c)
		i++;
	return (out[i]);
}

int	ident(int *tab)
{
	if (ft_isconver(tab[12]) == 0)
		return (-1);
	return (conv_data(tab[12]));
}

int	ft_id(void)
{
	return (1);
}
