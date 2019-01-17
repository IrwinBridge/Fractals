/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:24:04 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 18:26:49 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		render(t_engine *engine)
{
	clear_image(engine->image, 0xFFFFFF);

	julia_fractal(engine);

	mlx_put_image_to_window(engine->mlx, engine->window,
							engine->image->image, 0, 0);
	return (0);
}
