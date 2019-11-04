/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:16:18 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/05 14:11:05 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_same_one(int **t)
{
	int *tab;

	tab = *t;
	if (tab[11] == 'l' && tab[12] == 'c')
	{
		tab[11] = 0;
		tab[12] = 'C';
	}
	if (tab[11] == 'l' && tab[12] == 's')
	{
		tab[11] = 0;
		tab[12] = 'S';
	}
	if (tab[12] == 'U')
	{
		tab[10] = 0;
		tab[11] = 'l';
		tab[12] = 'u';
	}
}

void	ft_same_two(int **t)
{
	int *tab;

	tab = *t;
	if (tab[12] == 'O')
	{
		tab[10] = 0;
		tab[11] = 'l';
		tab[12] = 'o';
	}
	if (tab[12] == 'D')
	{
		tab[10] = 0;
		tab[11] = 'l';
		tab[12] = 'd';
	}
	if (tab[12] == 'F')
	{
		tab[10] = 0;
		tab[11] = 'l';
		tab[12] = 'f';
	}
}

void	ft_same(int **t)
{
	int *tab;

	tab = *t;
	if (tab[12] == 'c' || tab[12] == 's' || tab[12] == 'U')
		return (ft_same_one(t));
	if (tab[12] == 'O' || tab[12] == 'D' || tab[12] == 'F')
		return (ft_same_two(t));
}
