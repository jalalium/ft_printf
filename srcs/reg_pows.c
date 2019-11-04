/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_pows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:07:52 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 18:51:31 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	pw_f(int x)
{
	return (x > 0 ? pw_f(x - 1) * 5 : 1);
}

unsigned long long	pw_t(int x)
{
	return (x > 0 ? pw_f(x - 1) * 10 : 1);
}

unsigned long long	pow_two(int x)
{
	return (x > 0 ? pow_two(x - 1) * 2 : 1);
}
