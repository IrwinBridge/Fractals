/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:35:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/21 23:48:33 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_pixel(t_engine *engine, int x, int y)
{
	t_compl	new;
	t_compl	old;
	int		i;
	int		color;

	i = 0;
	transform(engine->camera, &new, x, y);
	while (i < engine->fractal->max_iterations)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + engine->fractal->c.r;
		new.i = 2.0f * old.r * old.i + engine->fractal->c.i;
		if ((new.r * new.r + new.i * new.i) > 4.0f)
			break ;
		i++;
	}
	color = set_fractal_color(hsv2rgb(get_i_color(engine, i)));
	*(int *)(engine->image->info + ((x + y * WINDOW_WIDTH)
			* engine->image->bpp)) = color;
	return (i);
}

void	julia_camera(t_engine *engine)
{
	engine->camera->xmin = -2.0f;
	engine->camera->xmax = 2.0f;
	engine->camera->ymin = -2.0f;
	engine->camera->ymax = 2.0f;
}
