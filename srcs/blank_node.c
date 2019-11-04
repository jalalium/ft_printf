/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:59:17 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 13:33:33 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	blank_node(void)
{
	t_data	start;

	start.str = 0;
	start.adr = 0;
	start.val = 0;
	start.flt = 0;
	return (start);
}
