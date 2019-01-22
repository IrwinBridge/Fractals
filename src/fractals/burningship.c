/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 22:59:15 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/21 23:48:02 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		burningship_pixel(t_engine *engine, int x, int y)
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
		old.r = fabs(new.r);
		old.i = fabs(new.i);
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

void	burningship_camera(t_engine *engine)
{
	engine->camera->xmin = -2.0f;
	engine->camera->xmax = 1.0f;
	engine->camera->ymin = -2.0f;
	engine->camera->ymax = 1.0f;
	engine->camera->x_offset = -0.25f;
}
