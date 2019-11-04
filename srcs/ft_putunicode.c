/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:44:01 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 23:58:16 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunicode_one(int n)
{
	int c;

	c = n;
	write(1, &c, 1);
	return (1);
}

int	ft_putunicode_two(int n)
{
	int c;

	c = 192 + n / 64;
	write(1, &c, 1);
	c = 128 + n % 64;
	write(1, &c, 1);
	return (2);
}

int	ft_putunicode_three(int n)
{
	int c;

	c = 224 + n / 4096;
	write(1, &c, 1);
	c = 128 + (n % 4096) / 64;
	write(1, &c, 1);
	c = 128 + n % 64;
	write(1, &c, 1);
	return (3);
}

int	ft_putunicode_four(int n)
{
	int c;

	c = 240 + n / 262144;
	write(1, &c, 1);
	c = 128 + (n % 262144) / 4096;
	write(1, &c, 1);
	c = 128 + (n % 4096) / 64;
	write(1, &c, 1);
	c = 128 + n % 64;
	write(1, &c, 1);
	return (4);
}
