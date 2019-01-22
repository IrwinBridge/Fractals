/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:15:10 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 15:58:36 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*src_copied;

	ptr = (unsigned char *)dst;
	src_copied = (unsigned char *)src;
	if (src_copied > ptr)
		return (ft_memcpy(dst, src, len));
	while (len)
	{
		len--;
		*(ptr + len) = *(src_copied + len);
	}
	return (dst);
}
