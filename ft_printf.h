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
	int		width;
	int		precision;
}				t_flags;

/*
** ========== PROTOTYPES ==========
*/
int				ft_printf(const char *format, ...);
t_flags			*get_flags(const char *format, int *index, va_list ap);
t_flags			*flag_init();
char			get_type(const char *format, int index);
char			*get_arg(t_printf *vars, va_list ap);
void			ft_display(const char *format, t_printf *vars, t_flags *flags);
int				is_valide_type(char c);
int				is_int(char type);
int				is_hex(char type);
int				is_char(char type);
int				is_str(char type);
int				get_char_number(t_flags *flags, t_printf *vars);
#endif