/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:28:02 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/06 17:14:46 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst = (char *)ft_memmove(dst, s1, len);
	dst[len] = '\0';
	return (dst);
}
