/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:32:02 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 19:32:05 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_int(char type)
{
	if (type == 'i' || type == 'd' || type == 'u')
		return (1);
	return (0);
}

int	is_hex(char type)
{
	if (type == 'x' || type == 'X' || type == 'p')
		return (1);
	return (0);
}

int	is_char(char type)
{
	if (type == 'c' || type == '%')
		return (1);
	return (0);
}

int	is_str(char type)
{
	if (type == 's')
		return (1);
	return (0);
}

int is_valide_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 's' || c == 'c' || c == '%')
		return (1);
	if (c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
