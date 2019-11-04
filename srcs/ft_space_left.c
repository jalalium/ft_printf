/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:18:44 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/04 23:55:37 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sl_unistr(int *tab, int len)
{
	int e;
	int count;

	count = tab[7] - len;
	e = count;
	if (tab[4] != 0 || tab[6] == 0 || count <= 0)
		return (0);
	while (count)
	{
		if (tab[2] != 0)
			ft_putstr("0");
		else
			ft_putstr(" ");
		count--;
	}
	return (e);
}

int	ft_sl_str(int *tab, int len)
{
	int e;
	int count;

	if (tab[12] == 'S')
		return (ft_sl_unistr(tab, len));
	count = tab[7] - len;
	e = count;
	if (tab[4] != 0 || tab[6] == 0 || count <= 0)
		return (0);
	while (count)
	{
		if (tab[2] != 0)
			ft_putstr("0");
		else
			ft_putstr(" ");
		count--;
	}
	return (e);
}

int	ft_sl_num(int **t, int len)
{
	int *tab;
	int count;
	int e;

	tab = *t;
	count = tab[7] - len;
	if (tab[8] != 0)
		count = tab[7] - (len > tab[9] ? len : tab[9]);
	e = count;
	if (tab[4] != 0 || tab[6] == 0 || count <= 0)
		return (0);
	while (count)
	{
		if (tab[2] != 0 && ((tab[8] == 0) || tab[12] == 'c'))
			ft_putstr("0");
		else
			ft_putstr(" ");
		count--;
	}
	return (e);
}

int	ft_sl_spe(int *tab, int len)
{
	int count;
	int e;

	count = tab[7] - len;
	e = count;
	if (tab[4] != 0 || tab[6] == 0 || count <= 0)
		return (0);
	while (count)
	{
		if (tab[2] != 0)
			ft_putstr("0");
		else
			ft_putstr(" ");
		count--;
	}
	return (e);
}

int	ft_space_left(int **t, int len, int state)
{
	int *tab;

	tab = *t;
	if (state == 0)
		return (ft_sl_str(tab, len));
	if (state == 1 || state == 2 || state == 3)
		return (ft_sl_num(t, len));
	if (state == 4 || state == 5)
		return (ft_sl_spe(tab, len));
	return (0);
}
