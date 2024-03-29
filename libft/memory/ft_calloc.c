/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:54:36 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/10/23 11:40:22 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (count * size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(dest = (void *)malloc(size * count)))
		return (0);
	ft_memset(dest, '\0', size * count);
	return (dest);
}
