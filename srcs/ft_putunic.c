/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:40:52 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 23:45:26 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenunicode(int n)
{
	if (n < 128)
		return (1);
	else if (n < 2048)
		return (2);
	else if (n < 65536)
		return (3);
	else
		return (4);
}

int	ft_putunicode(int n)
{
	if (n < 128)
		return (ft_putunicode_one(n));
	else if (n < 2048)
		return (ft_putunicode_two(n));
	else if (n < 65536)
		return (ft_putunicode_three(n));
	else
		return (ft_putunicode_four(n));
}
