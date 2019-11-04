/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:20:34 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:17:23 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	get_string(va_list ap, int *tab)
{
	t_data	node;
	char	*err;
	wchar_t	*er;

	err = (char*)malloc(sizeof(char) * 6);
	er = (wchar_t*)malloc(sizeof(char) * 6);
	err = "(null)";
	er = L"(null)";
	if (!(node.str = va_arg(ap, char*)))
	{
		if (tab[12] == 'S')
			node.str = (char*)er;
		else
			node.str = err;
	}
	return (node);
}

t_data	get_pointer(va_list ap)
{
	t_data node;

	node.adr = va_arg(ap, long);
	return (node);
}

t_data	get_float(int *tab, va_list ap)
{
	t_data node;

	if (tab[11] == 'L')
	{
		node.flt = va_arg(ap, long double);
	}
	else
		node.flt = va_arg(ap, double);
	return (node);
}

t_data	get_number(int *tab, va_list ap)
{
	t_data node;

	if (tab[12] == 'c' || (tab[10] == 'h' && tab[11] == 'h'))
		node.val = (char)va_arg(ap, int);
	else if (tab[10] == 0 && tab[11] == 'h')
		node.val = (short)va_arg(ap, int);
	else if ((tab[10] == 0 && tab[11] == 'l'))
		node.val = va_arg(ap, long);
	else if ((tab[10] == 'l' && tab[11] == 'l') || tab[11] == 'z')
		node.val = va_arg(ap, long long);
	else if (tab[10] == 0 && tab[11] == 'j')
		node.val = va_arg(ap, intmax_t);
	else
		node.val = va_arg(ap, int);
	return (node);
}

t_data	get_data(va_list ap, int *tab, int s)
{
	if (s == 0)
		return (get_string(ap, tab));
	else if (s == 1)
		return (get_pointer(ap));
	else if (s == 2)
		return (get_float(tab, ap));
	else
		return (get_number(tab, ap));
}
