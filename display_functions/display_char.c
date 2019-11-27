/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:45:04 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 22:45:08 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void display_char(t_printf *vars, t_flags *flags, int nb_char, int nb_space)
{
	if (flags->flag == '-')
	{
		ft_putchar(vars->arg[0]);
		ft_putnchar(' ', nb_space);
	}
	else if (flags->flag == '0')
	{
		ft_putnchar('0', nb_space);
		ft_putchar(vars->arg[0]);
	}
	else
	{
		ft_putnchar(' ', nb_space);
		ft_putchar(vars->arg[0]);
	}
}