/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:55:23 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 14:55:27 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char *get_char(char type, va_list ap)
{
	char *arg;

	if (!(arg = (char *)malloc(2 * sizeof(char))))
		return (NULL);
	if (type == '%')
		arg[0] = '%';
	else
		arg[0] = va_arg(ap, int);
	arg[1] = '\0';
	return (arg);
}

char *get_arg(char type, va_list ap, int *index)
{
	char *arg;

	if (type == 'i' || type == 'd')
		arg = ft_itoa(va_arg(ap, int));
	else if (type == 'c' || type == '%')
		arg = get_char(type, ap);
	else if (type == 's')
		arg = va_arg(ap, char *);
	else if (type == 'x' || type == 'X')
		arg = ft_itohex(va_arg(ap, int));
	// else if (type == 'p')
		// arg = get_address((long)va_arg(ap, void *));
	else
		(*index)++;
	return (arg);
}