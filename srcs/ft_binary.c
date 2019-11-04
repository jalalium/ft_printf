/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:08:33 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 20:05:53 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		two_pow_bin(int r)
{
	int n;

	if (r == 0)
		return (1);
	n = 2;
	while (--r)
		n *= 2;
	return (n);
}

int		ft_log_bin(int n)
{
	return (n >= 1 ? 1 + ft_log_bin(n / 2) : 0);
}

int		ft_len_bin(int nb)
{
	return (ft_log_bin(nb));
}

int		ft_binary(int nb)
{
	char	*out;
	int		i;

	out = ft_strnew(ft_log_bin(nb) + 1);
	i = (nb == 0 ? 1 : ft_log_bin(nb));
	while (i > 0)
	{
		out[i - 1] = nb % 2 + '0';
		nb /= 2;
		i--;
	}
	ft_putstr(out);
	free(out);
	return (1);
}
