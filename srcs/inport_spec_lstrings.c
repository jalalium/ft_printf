/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inport_spec_strings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:01:37 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 22:09:35 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**inport_spec_lstrings(void)
{
	char **out;

	out = (char**)malloc(sizeof(char*) * 4);
	out[0] = (char*)malloc(sizeof(char*) * 80);
	out[0] = pr_ldbl(1. / 0);
	out[1] = (char*)malloc(sizeof(char*) * 80);
	out[1] = pr_ldbl(-1. / 0);
	out[2] = (char*)malloc(sizeof(char*) * 80);
	out[2] = pr_ldbl(0. / 0.);
	out[3] = (char*)malloc(sizeof(char*) * 80);
	out[3] = pr_ldbl(0. / 0.);
	return (out);
}
