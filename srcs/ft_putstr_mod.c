/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:59:01 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/11/18 20:12:46 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_mod(char *s, int *tab)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (i < tab[9] || tab[8] == 0))
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
