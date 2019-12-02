/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:45:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 14:11:13 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putint(t_printf *vars, t_flags *flags, int nb_char)
{
	int	i;
	int	nb_zero;

	i = 0;
	if (vars->arg[i] == '-')
	{
		ft_putchar('-');
		i++;
		nb_char--;
	}
	nb_zero = nb_char - ft_strlen(&(vars->arg[i]));
	if (nb_zero > 0)
		ft_putnchar('0', nb_zero);
	if (ft_atoi(vars->arg) == 0 && flags->precision == 0)
	{
		if (flags->width == -1 || flags->width == 0)
			vars->return_size--;
		else
			ft_putchar(' ');
	}
	else
		ft_putstr(&(vars->arg[i]));
}

void		display_int(t_printf *vars, t_flags *fl, int nb_char, int nb_space)
{
	if (fl->flag == '-')
	{
		ft_putint(vars, fl, nb_char);
		ft_putnchar(' ', nb_space);
	}
	else if (fl->flag == '0')
	{
		if (nb_space > 0 && fl->precision == -1)
			ft_putint(vars, fl, nb_space + nb_char);
		else
		{
			ft_putnchar(' ', nb_space);
			ft_putint(vars, fl, nb_char);
		}
	}
	else
	{
		ft_putnchar(' ', nb_space);
		ft_putint(vars, fl, nb_char);
	}
}
