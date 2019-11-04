/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:17:17 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:17:01 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_mod(char *str, int *tab)
{
	int len;

	if (tab[12] == 'S')
		return (ft_lenunistr(str, tab));
	len = ft_strlen(str);
	if (tab[8] == 0)
		return (len);
	return ((len > tab[9] ? tab[9] : len));
}
