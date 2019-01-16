/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:37:59 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/05 16:51:31 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;

	if (size == (size_t)-1)
		return (NULL);
	if (!(p = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
