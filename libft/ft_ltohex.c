/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:43:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/26 17:43:28 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long get_size(long l)
{
	long size;

	size = 0;
	while (l != 0)
	{
		l /= 16;
		size++;
	}
	return (size);
}

static long ft_neg(long l)
{
	long max;

	max = 4294967295;
	l = max - l + 1;
	return (l);
}

char *ft_ltohex(long l)
{
	char	*base;
	char	*hex;
	long	len;
	long	i;

	base = ft_strdup("0123456789abcdef");
	if (l == 0)
		return ("0");
	if (l < 0)
		l = ft_neg(-l);
	len = get_size(l);
	if (!(hex = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 1;
	while (l)
	{
		hex[len - i++] = base[l % 16];
		l /= 16;
	}
	hex[len] = '\0';
	free(base);
	return (hex);
}