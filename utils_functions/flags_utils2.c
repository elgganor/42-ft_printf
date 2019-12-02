/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:21:38 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 10:21:40 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int get_precision_star(const char *format, int *index, t_flags *flags)
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
		return (-1);
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
