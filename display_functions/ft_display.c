/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:25:32 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 10:25:34 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_display(t_printf *vars, t_flags *flags)
{
	int	nb_char_to_print;
	int	nb_space_to_print;

	nb_char_to_print = get_char_number(flags, vars);
	nb_space_to_print = get_space_number(flags, nb_char_to_print);
	vars->return_size += nb_char_to_print + nb_space_to_print;
	if (is_int(vars->type))
		display_int(vars, flags, nb_char_to_print, nb_space_to_print);
	else if (is_char(vars->type))
		display_char(vars, flags, nb_char_to_print, nb_space_to_print);
	else if (is_str(vars->type))
		display_str(vars, flags, nb_char_to_print, nb_space_to_print);
	else if (is_hex(vars->type))
		display_hex(vars, flags, nb_char_to_print, nb_space_to_print);
}