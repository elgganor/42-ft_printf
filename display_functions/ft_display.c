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

void	ft_display(const char *format, t_printf *vars, t_flags *flags)
{
	int	nb_char_to_print;
	int	nb_space_to_print;

	nb_char_to_print = get_char_number();
	nb_space_to_print = get_space_number();
}