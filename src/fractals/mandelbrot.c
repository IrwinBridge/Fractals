/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 22:46:40 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/21 23:48:28 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_pixel(t_engine *engine, int x, int y)
{
	t_compl	p;
	t_compl	new;
	t_compl	old;
	int		i;
	int		color;

	i = -1;
	transform(engine->camera, &p, x, y);
	new.r = 0;
	new.i = 0;
	old.r = 0;
	old.i = 0;
	while (++i < engine->fractal->max_iterations)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + p.r;
		new.i = 2.0f * old.r * old.i + p.i;
		if ((new.r * new.r + new.i * new.i) > 4.0f)
			break ;
	}
	color = set_fractal_color(hsv2rgb(get_i_color(engine, i)));
	*(int *)(engine->image->info + ((x + y * WINDOW_WIDTH)
			* engine->image->bpp)) = color;
	return (i);
}

void	mandelbrot_camera(t_engine *engine)
{
	engine->camera->xmin = -2.0f;
	engine->camera->xmax = 1.0f;
	engine->camera->ymin = -1.0f;
	engine->camera->ymax = 1.0f;
	engine->camera->x_offset = -0.5f;
}
