/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:41:03 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 18:48:36 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (ft_memcmp(s1, s2, len1));
	else
		return (ft_memcmp(s1, s2, len2));
	return (0);
}
