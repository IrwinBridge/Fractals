/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:44:08 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 14:06:36 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = *(unsigned char *)src++;
		i++;
	}
	return (dst);
}
