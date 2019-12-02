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
# include <limits.h>
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
void			ft_display(t_printf *vars, t_flags *flags);
int				is_valide_type(char c);
int				is_int(char type);
int				is_hex(char type);
int				is_char(char type);
int				is_str(char type);
int				get_char_number(t_flags *flags, t_printf *vars);
int				get_space_number(t_flags *flags, int nb_char);
void			display_char(t_printf *v, t_flags *fl, int nchar , int space);
void			display_str(t_printf *v, t_flags *fl, int nchar , int space);
void			display_int(t_printf *v, t_flags *fl, int nchar , int space);
void			display_hex(t_printf *v, t_flags *fl, int nchar , int space);
void			ft_putnchar(char c, size_t n);
void			ft_putnstr(char *str, size_t n);
int				get_precision(const char *f, int *index, t_flags *flags);
int				get_width(const char *f, int *index, char *flag);
char			get_flag(const char *f, int *index);
int				get_precision_star(const char *f, int *index, t_flags *flags);
int				get_width_star(const char *f, int *index, char *flag);
#endif