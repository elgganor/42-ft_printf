/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:00:23 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/27 11:00:24 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int get_space_number(t_flags *flags, int nb_char)
{
	if (!flags || flags->width == -1)
		return (0);
	if (flags->width > nb_char)
		return (flags->width - nb_char);
	else
		return (0);
}