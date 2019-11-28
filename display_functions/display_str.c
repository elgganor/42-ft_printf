/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:45:16 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 22:45:19 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void display_str(t_printf *vars, t_flags *flags, int nb_char, int nb_space)
{
	if (flags->flag == '-')
	{
		ft_putnstr(vars->arg, nb_char);
		ft_putnchar(' ', nb_space);
	}
	else if (flags->flag == '0')
	{
		ft_putnchar('0', nb_space);
		ft_putnstr(vars->arg, nb_char);
	}
	else
	{
		ft_putnchar(' ', nb_space);
		ft_putnstr(vars->arg, nb_char);
	}
}