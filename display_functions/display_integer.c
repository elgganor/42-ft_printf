/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:45:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 22:45:14 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// is_part_case
// manage_part_case
static void	ft_putint(t_printf *vars, t_flags *flags, int nb_char)
{
	int	i;
	int	nb_zero;

	i = 0;
	if (vars->arg[i] == '-' && vars->type != 'u')
	{
		ft_putchar('-');
		i++;
		nb_char--;
	}
	nb_zero = nb_char - ft_strlen(&(vars->arg[i]));
	if (nb_zero > 0)
		ft_putnchar('0', nb_zero);
	if (ft_atoi(vars->arg) == 0 && flags->precision == 0)
		vars->return_size--;
	else
		ft_putstr(&(vars->arg[i]));
}

void display_int(t_printf *vars, t_flags *flags, int nb_char, int nb_space)
{
	if (flags->flag == '-')
	{
		ft_putint(vars, flags, nb_char);
		ft_putnchar(' ', nb_space);
	}
	else if (flags->flag == '0')
	{
		if (nb_space > 0 && flags->precision == -1)
			ft_putint(vars, flags, nb_space + nb_char);
		else
		{
			ft_putnchar(' ', nb_space);
			ft_putint(vars, flags, nb_char);
		}
	}
	else
	{
		ft_putnchar(' ', nb_space);
		ft_putint(vars, flags, nb_char);
	}
}