/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:45:09 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 14:11:10 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_puthex(t_printf *vars, t_flags *flags, int nb_char)
{
	int i;
	int nb_zero;

	i = 0;
	if (vars->type == 'p')
	{
		ft_putstr("0x");
		nb_char -= 2;
	}
	nb_zero = nb_char - ft_strlen(vars->arg);
	if (nb_zero > 0)
		ft_putnchar('0', nb_zero);
	if (ft_strcmp(vars->arg, "0") == 0 && flags->precision == 0)
	{
		if (flags->width == -1)
			vars->return_size--;
		else
			ft_putchar(' ');
	}
	else
		ft_putstr(&(vars->arg[i]));
}

void		display_hex(t_printf *vars, t_flags *fl, int nb_char, int nb_space)
{
	if (fl->flag == '-')
	{
		ft_puthex(vars, fl, nb_char);
		ft_putnchar(' ', nb_space);
	}
	else if (fl->flag == '0')
	{
		if (nb_space > 0 && fl->precision == -1)
			ft_puthex(vars, fl, nb_space + nb_char);
		else
		{
			ft_putnchar(' ', nb_space);
			ft_puthex(vars, fl, nb_char);
		}
	}
	else
	{
		ft_putnchar(' ', nb_space);
		ft_puthex(vars, fl, nb_char);
	}
}
