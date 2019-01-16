/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:11:36 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 00:03:40 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	usage_exit(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

void	error_exit(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

void	success_exit(t_engine *engine)
{
	free_engine(engine);
	exit(EXIT_SUCCESS);
}