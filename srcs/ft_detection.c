/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:15:46 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 13:34:04 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isconver(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'u' ||
c == 'x' || c == 'X' || c == 'f' || c == 'F' || c == 'b' ||
c == 'c' || c == 'U' || c == 'O')
		return (1);
	if (c == 's' || c == 'p' || c == 'C' || c == 'S')
		return (2);
	return (0);
}

int	flags_det(int **tap, int i, const char *s)
{
	int *tab;

	tab = *tap;
	if (s[0] == '%')
	{
		tab[0]++;
		return (1);
	}
	while (s[i] == '#' || s[i] == '%' || s[i] == '0' || s[i] == '+' ||
s[i] == '-' || s[i] == ' ')
	{
		tab[0] = (s[i] == '%' ? i + 1 : tab[0]);
		tab[1] = (s[i] == '#' ? tab[1] + 1 : tab[1]);
		tab[2] = (s[i] == '0' ? tab[2] + 1 : tab[2]);
		tab[3] = (s[i] == '+' ? tab[3] + 1 : tab[3]);
		tab[4] = (s[i] == '-' ? tab[4] + 1 : tab[4]);
		tab[5] = (s[i] == ' ' ? tab[5] + 1 : tab[5]);
		i++;
	}
	return (i);
}

int	minwidth_det(int **tap, int i, const char *s, va_list ap)
{
	int *tab;

	tab = *tap;
	while (ft_isdigit(s[i]) || s[i] == '*')
	{
		if ((ft_isdigit(s[i])))
		{
			tab[6] = 2;
			tab[7] = ft_atoi(s + i);
			i += (tab[7] == 0 ? 1 : ft_log(tab[7]));
		}
		if (s[i] == '*')
		{
			tab[6] = 1;
			tab[7] = va_arg(ap, int);
			i++;
		}
	}
	return (i);
}

int	prec_det(int **tap, int i, const char *s, va_list ap)
{
	int *tab;

	tab = *tap;
	if (s[i] == '.')
	{
		tab[8] = 1;
		tab[9] = 0;
		i++;
	}
	if (s[i] == '*')
	{
		if (tab[8] == 1)
			tab[9] = va_arg(ap, int);
		else
			tab[13] = va_arg(ap, int);
		i++;
	}
	if ((ft_isdigit(s[i])) && s[i - 1] != '*' && tab[8] == 1)
	{
		tab[8] = 2;
		tab[9] = ft_atoi(s + i);
		i += (tab[9] == 0 ? 1 : ft_log(tab[9]));
	}
	return (i);
}

int	convers_det(int **tap, int i, const char *s)
{
	int *tab;

	tab = *tap;
	if ((s[i] == 'h' || s[i] == 'l') && (s[i + 1] == 'h' || s[i + 1] == 'l'))
	{
		tab[10] = s[i];
		i++;
	}
	if (s[i] == 'h' || s[i] == 'l' || s[i] == 'L' || s[i] == 'j' || s[i] == 'z')
	{
		tab[11] = s[i];
		i++;
	}
	if ((ft_isalpha(s[i])) || s[i] == '%')
	{
		if ((ft_isconver(s[i])))
			tab[12] = s[i];
		else
			tab[12] = -1 * s[i];
		i++;
	}
	return (i);
}
