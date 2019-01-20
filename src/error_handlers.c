/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:11:36 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/20 13:04:02 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage_exit(void)
{
	ft_putendl("Usage: ./fractol <fractal name>");
	ft_putendl("Available fractals:");
	ft_putendl("\t--> julia\n\t--> mandelbrot\n\t--> burningship");
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

void	get_fname(t_engine *engine, char *name)
{
	if (!ft_strcmp(name, "julia"))
		engine->fractal->name = JULIA;
	else if (!ft_strcmp(name, "mandelbrot"))
		engine->fractal->name = MANDELBROT;
	else if (!ft_strcmp(name, "burningship"))
		engine->fractal->name = BURNINGSHIP;
	else
	{
		ft_putendl("No such fractal name in a list.");
		success_exit(engine);
	}
}
