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

t_flags	*get_flags(const char *f, int *index, va_list ap)
{
	t_flags	*fl;
	int		z;

	fl = flag_init();
	if (f[*index] == '-' || f[*index] == '0')
		fl->flag = get_flag(f, index);
	if (f[*index] == '*')
	{
		z = 0;
		fl->width = get_width(ft_itoa(va_arg(ap, int)), &z, &(fl->flag));
		(*index)++;
	}
	else if (ft_isdigit(f[*index]) || f[*index] == '-')
		fl->width = get_width(f, index, &(fl->flag));
	if (f[*index] == '.' && (ft_isdigit(f[++(*index)]) || f[*index] == '-'))
		fl->precision = get_precision(f, index, fl);
	else if (f[*index - 1] == '.' && f[(*index)] == '*')
	{
		z = 0;
		fl->precision = get_precision_star(ft_itoa(va_arg(ap, int)), &z, fl);
		(*index)++;
	}
	else if (f[*index - 1] == '.')
		fl->precision = 0;
	return (fl);
}
