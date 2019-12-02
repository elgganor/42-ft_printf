/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:55:28 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 14:55:33 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags *get_flags(const char *format, int *index, va_list ap)
{
	t_flags *flags;
	int		z;

	flags = flag_init();
	// flag
	if (format[*index] == '-' || format[*index] == '0')
		flags->flag = get_flag(format, index);


	// width
	if (format[*index] == '*')
	{
		z = 0;
		flags->width = get_width(ft_itoa(va_arg(ap, int)), &z, &(flags->flag));
		(*index)++;
	}
	else if (ft_isdigit(format[*index]) || format[*index] == '-')
		flags->width = get_width(format, index, &(flags->flag));


	// precision
	if (format[*index] == '.' && (ft_isdigit(format[++(*index)]) || format[*index] == '-'))
		flags->precision = get_precision(format, index, flags);
	else if (format[*index - 1] == '.' && format[(*index)] == '*')
	{
		z = 0;
		flags->precision = get_precision_star(ft_itoa(va_arg(ap, int)), &z, flags);
		(*index)++;
	}
	else if (format[*index - 1] == '.')
		flags->precision = 0;


	return (flags);
}