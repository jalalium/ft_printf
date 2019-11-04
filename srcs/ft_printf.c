/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:09:37 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 19:54:13 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*g_len[]) () = {ft_id, ft_hex_length_mod, ft_oct_length_mod,
	ft_length_s_mod, ft_length_un_mod, ft_lenfloat_mod,
	ft_lenunicode, ft_lenunistr, ft_len_bin};

int (*g_poly_print[]) () = {ft_putstr_mod, ft_putchar_mod, ft_hex_mod,
	ft_oct_mod, ft_putnbr_s_mod, ft_putnbr_un_mod, ft_putfloat_mod,
	ft_putunicode, ft_putunistr, ft_binary};

int		*routine_id(const char *s, va_list ap)
{
	int *tab;
	int i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * 14);
	while (i < 14)
		tab[i++] = 0;
	i = 0;
	tab[9] = -1;
	i = flags_det(&tab, i, s);
	if (tab[0] != 0)
		return (tab);
	i = minwidth_det(&tab, i, s, ap);
	i = prec_det(&tab, i, s, ap);
	tab[13] = convers_det(&tab, i, s);
	ft_same(&tab);
	ft_adjust(&tab);
	return (tab);
}

int		len_mod(int *tab, t_data data_p, int state)
{
	int len;

	if (state == 1)
		len = g_len[ident(tab) - 1](data_p.adr, tab, 1);
	else if (state == 0)
		len = ft_strlen_mod(data_p.str, tab);
	else if (state == 2)
		len = g_len[ident(tab) - 1](data_p.flt, tab, 1);
	else if (state == 3)
		len = g_len[ident(tab) - 1](data_p.val, tab, 1);
	else if (state == 5)
		len = 1;
	else
		len = 0;
	return (len);
}

void	poly_p_module(int *tab, t_data data_p, int state)
{
	if (state == 1)
		g_poly_print[ident(tab)](data_p.adr, tab);
	else if (state == 0)
		g_poly_print[ident(tab)](data_p.str, tab);
	else if (state == 2)
		g_poly_print[ident(tab)](data_p.flt, tab);
	else if (state == 3)
		g_poly_print[ident(tab)](data_p.val, tab);
	else if (state == 5)
		ft_putchar(-1 * tab[12]);
	else
		return ;
}

int		manage_routine(va_list ap, int *tab)
{
	t_data	node;
	int		state;
	int		len;

	state = 10;
	node = blank_node();
	if (errors_det(tab, 0) != -1)
		return (errors_det(tab, 1));
	state = spec_cases(tab[12]);
	if (state == 10)
	{
		state = get_state(tab);
		node = get_data(ap, tab, state);
	}
	len = len_mod(tab, node, state);
	len += ft_space_left(&tab, len, state);
	poly_p_module(tab, node, state);
	len += ft_space_right(tab, len);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		*temp;

	va_start(ap, format);
	i = 0;
	j = 0;
	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			temp = routine_id(format + i + 1, ap);
			i += count_skip(temp) + 1;
			j += manage_routine(ap, temp);
		}
		if (i < (int)ft_strlen(format) && format[i] != '%')
		{
			ft_putchar(format[i]);
			j++;
			i++;
		}
	}
	va_end(ap);
	return (j);
}
