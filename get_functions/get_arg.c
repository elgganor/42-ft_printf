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

char *get_arg(t_printf *vars, va_list ap)
{
	char *arg;

	if (vars->type == 'i' || vars->type == 'd')
		arg = ft_itoa(va_arg(ap, int));
	else if (vars->type == 'c' || vars->type == '%')
		arg = get_char(vars->type, ap);
	else if (vars->type == 's')
	{
		arg = va_arg(ap, char *);
		if (arg == NULL)
			arg = ft_strdup("(null)");
	}
	else if (vars->type == 'x' || vars->type == 'X')
	{
		arg = ft_itohex(va_arg(ap, int));
		arg = (vars->type == 'X') ? ft_strtoupper(arg) : arg;
	}
	else if (vars->type == 'p')
		arg = ft_ltohex((long)va_arg(ap, void *));
	else if (vars->type == 'u')
		arg = ft_ltoa(ft_itou(va_arg(ap, int)));
	else
		vars->index++;
	return (arg);
}