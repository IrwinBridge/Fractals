/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:07:53 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 18:05:52 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_hook(engine->window, E_KEY_RELEASE,	  1L << 1, key_release, engine);
	mlx_hook(engine->window, E_MOUSE_PRESS,	  1L << 2, hook_mousedown, engine);
	mlx_hook(engine->window, E_MOUSE_RELEASE, 1L << 3, hook_mouseup, engine);
	mlx_hook(engine->window, E_MOUSE_MOVE,	  1L << 6, hook_mousemove, engine);
	mlx_loop(engine->mlx);
	(void)argv;
	return (0);
}
