/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:07:53 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 22:10:58 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	setting(t_engine *engine)
{
	engine->camera->x_offset = 0.0f;
	engine->camera->y_offset = 0.0f;
	engine->camera->zoom = 1.0f;
	engine->camera->scale_factor = 2.0f;
	engine->camera->hue = 0.0f;
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
	setting(engine);
	render(engine);
	mlx_hook(engine->window, E_KEY_RELEASE, KeyReleaseMask, key_release, engine);
	mlx_hook(engine->window, 4, ButtonPressMask, hook_mousedown, engine);
	mlx_hook(engine->window, 5, ButtonReleaseMask, hook_mouseup, engine);
	mlx_hook(engine->window, 6, PointerMotionMask, hook_mousemove, engine);
	//mlx_loop_hook(engine->mlx, render, engine);
	mlx_loop(engine->mlx);
	(void)argv;
	return (0);
}
