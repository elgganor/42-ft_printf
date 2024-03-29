/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:18:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/28 00:18:39 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnchar(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(str[i++]);
}
