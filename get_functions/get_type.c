/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:55:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 14:55:37 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	get_type(const char *format, int index)
{
	char	type;

	if (is_valide_type(format[index]) == 1)
		type = format[index];
	else
		type = '\0';
	return (type);
}
