/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:15:27 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 14:15:28 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ========== INCLUDES ==========
*/
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include "./libft/libft.h"

/*
** ========== STRUCTURES ==========
*/
typedef struct s_printf
{
	int		index;
	int		return_size;
	char	*arg;
	char	type;
}				t_printf;
typedef struct	s_flags
{
	char	flag;
	char	*width;
	char	*precision;
}				t_flags;

/*
** ========== PROTOTYPES ==========
*/
int	ft_printf(const char *format, ...);
#endif