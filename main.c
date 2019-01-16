/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:07:53 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 23:32:00 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setting(t_engine *engine)
{
	engine->camera->x_offset = 0.0f;
	engine->camera->y_offset = 0.0f;
	engine->camera->scale = 1.0f;
}

/*
** TODO: Change usage to list all possible fractal arguments
*/

int		main(int argc, char **argv)
{
	t_engine	*engine;

	if (argc < 2)
		usage_exit("Usage: ./fractol <fractal name>");
	if (!(engine = initialize("Fractol")))
		error_exit("Error: MLX wasn't initialized");
	render(engine);
	mlx_hook(engine->window, E_KEY_RELEASE, KeyReleaseMask, key_release, engine);
	//mlx_loop_hook(engine->mlx, render, engine);
	mlx_loop(engine->mlx);
	(void)argv;
	return (0);
}
