/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:22:20 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 23:22:34 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_state(int *tab)
{
	if (tab[12] == 's' || tab[12] == 'S')
		return (0);
	else if (tab[12] == 'p')
		return (1);
	else if (tab[12] == 'f')
		return (2);
	else
		return (3);
}
