/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:00:17 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 11:00:19 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int get_char_number_str(t_flags *flags, t_printf *vars)
{
	// if (vars->arg == NULL)
	// 	return (6);
	if (flags->precision == -1)
		return (ft_strlen(vars->arg));
	else if (flags->precision == 0)
		return (0);
	else if (flags->precision >= ft_strlen(vars->arg))
		return (ft_strlen(vars->arg));
	else
		return (flags->precision);
}

static int get_char_number_int(t_flags *flags, t_printf *vars)
{
	int	nb_char;

	if (flags->precision == -1)
		nb_char = ft_strlen(vars->arg);
	if (flags->precision >= ft_strlen(vars->arg))
	{
		nb_char = flags->precision;
		if (vars->arg[0] == '-')
			nb_char++;
	}
	else
		nb_char = ft_strlen(vars->arg);
	return (nb_char);
}

static int get_char_number_hex(t_flags *flags, t_printf *vars)
{
	int nb_char;

	nb_char = 0;
	if (vars->type == 'p')
		nb_char = 2;
	if (flags->precision == -1)
		nb_char += ft_strlen(vars->arg);
	else if (flags->precision > ft_strlen(vars->arg))
		nb_char += flags->precision;
	else
		nb_char += ft_strlen(vars->arg);
	return (nb_char);
}

int	get_char_number(t_flags *flags, t_printf *vars)
{
	int	nb_char;

	if (is_char(vars->type))
		return (1);
	if (!flags)
		return (ft_strlen(vars->arg));
	if (is_str(vars->type))
		nb_char = get_char_number_str(flags, vars);
	else if (is_int(vars->type))
		nb_char = get_char_number_int(flags, vars);
	else if (is_hex(vars->type))
		nb_char = get_char_number_hex(flags, vars);
	return (nb_char);
}