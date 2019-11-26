/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:13:31 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 14:13:34 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void print_flags(t_flags *flags)
{
	printf("flag => %c\n", flags->flag);
	printf("width => %d\n", flags->width);
	printf("precision => %d\n", flags->precision);
}

void manage_display(const char *f, t_printf *vars, va_list ap)
{
	t_flags *flags;

	flags = get_flags(f, &(vars->index), ap);
	vars->type = get_type(f, vars->index);
	// print_flags(flags);
	// printf("type => %c\n", vars->type);
	vars->arg = get_arg(vars->type, ap, &(vars->index));
	printf("arg => %s\n", vars->arg);
	// ft_display();
	vars->index++;
	free(flags);
}

int	ft_printf(const char *format, ...)
{
	t_printf vars;
	va_list ap;

	vars.return_size = 0;
	vars.index = 0;
	va_start(ap, format);
	while (format[vars.index] != '\0')
	{
		if (format[vars.index] == '%')
		{
			vars.index++;
			manage_display(format, &vars, ap);
		}
		else
		{
			ft_putchar(format[vars.index]);
			vars.index++;
		}
	}
	va_end(ap);
	return (vars.return_size);
}