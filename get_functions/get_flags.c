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

static char get_flag(const char *format, int *index)
{
	char flag;

	flag = format[*index];
	while (format[*index] == '0' || format[*index] == '-')
	{
		if (format[*index] == '-')
			flag = '-';
		(*index)++;
	}
	return (flag);
}

static int	get_width(const char *format, int *index, char *flag)
{
	char	*width;
	int		i;
	int		size;

	i = *index;
	size = 0;
	if (format[i] == '-')
	{
		*flag = '-';
		i++;
		(*index)++;
	}
	while (ft_isdigit(format[i++]))
		size++;
	if (!(width = (char *)malloc(sizeof(char) * size)))
		return (-1);
	i = 0;
	while (ft_isdigit(format[*index]))
		width[i++] = format[(*index)++];
	width[i] = '\0';
	return (ft_atoi(width));
}

static int get_precision(const char *format, int *index)
{
	char	*precision;
	int		i;
	int		size;

	i = *index;
	size = 0;
	while (ft_isdigit(format[i++]))
		size++;
	if (!(precision = (char *)malloc(sizeof(char) * size)))
		return (-1);
	i = 0;
	while (ft_isdigit(format[*index]))
		precision[i++] = format[(*index)++];
	precision[i] = '\0';
	return (ft_atoi(precision));
}

t_flags *get_flags(const char *format, int *index, va_list ap)
{
	t_flags *flags;
	int		z;

	flags = flag_init();
	//flag
	if (format[*index] == '-' || format[*index] == '0')
		flags->flag = get_flag(format, index);
	//width
	if (format[*index] == '*')
	{
		z = 0;
		flags->width = get_width(ft_itoa(va_arg(ap, int)), &z, &(flags->flag));
		(*index)++;
	}
	else if (ft_isdigit(format[*index]))
		flags->width = get_width(format, index, &(flags->flag));
	//precision
	if (format[*index] == '.' && ft_isdigit(format[++(*index)]))
		flags->precision = get_precision(format, index);
	else if (format[*index - 1] == '.' && format[(*index)] == '*')
	{
		z = 0;
		flags->precision = get_precision(ft_itoa(va_arg(ap, int)), &z);
		(*index)++;
	}
	else if (format[*index - 1] == '.')
		flags->precision = 0;
	return (flags);
}