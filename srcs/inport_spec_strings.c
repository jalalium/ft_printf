/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inport_spec_strings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:01:37 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/12/10 20:25:45 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**inport_spec_strings(void)
{
	char **out;

	out = (char**)malloc(sizeof(char*) * 4);
	out[0] = (char*)malloc(sizeof(char*) * 64);
	out[0] = "0000000000000000000000000000000000000000000000000000111111111110";
	out[1] = (char*)malloc(sizeof(char*) * 64);
	out[1] = "0000000000000000000000000000000000000000000000000000111111111111";
	out[2] = (char*)malloc(sizeof(char*) * 64);
	out[2] = "0000000000000000000000000000000000000000000000000001111111111110";
	out[3] = (char*)malloc(sizeof(char*) * 12);
	out[3] = "111111111110";
	return (out);
}