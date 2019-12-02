/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:07:39 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 16:07:41 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags *flag_init()
{
	t_flags *flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->flag = '\0';
	flags->width = -1;
	flags->precision = -1;
	return (flags);
}


char	get_flag(const char *format, int *index)
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


int	get_width(const char *format, int *index, char *flag)
{
	char *width;
	int i;
	int size;

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
	if (!(width = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	i = 0;
	while (ft_isdigit(format[*index]))
		width[i++] = format[(*index)++];
	width[i] = '\0';
	i = ft_atoi(width);
	free(width);
	return (i);
}


int	get_precision(const char *format, int *index, t_flags *flags)
{
	char *precision;
	int i;
	int size;

	i = *index;
	size = 0;
	if (format[i] == '-')
	{
		flags->flag = '-';
		i++;
		(*index)++;
	}
	while (ft_isdigit(format[i++]))
		size++;
	if (!(precision = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	i = 0;
	while (ft_isdigit(format[*index]))
		precision[i++] = format[(*index)++];
	precision[i] = '\0';
	i = ft_atoi(precision);
	free(precision);
	return (i);
}