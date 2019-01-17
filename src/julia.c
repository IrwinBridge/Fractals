/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:35:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 23:08:32 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

int		julia_calculate(t_point *new, t_point *old, t_point c)
{
	int i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		old->x = new->x;
		old->y = new->y;

		new->x = old->x * old->x - old->y * old->y + c.x;
		new->y = 2 * old->x * old->y + c.y;
		if ((new->x * new->x + new->y * new->y) > 4)
			break ;
		i++;
	}
	return (i);
}

void	julia_fractal(t_engine *engine)
{
	t_point	c;
	t_point	old;
	t_point	new;
	int		color;
	int		x;
	int		y;

	c.x = -0.7f;
	c.y = 0.27015;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			new.x = 1.5f * (x - WINDOW_WIDTH / 2) /
					(0.5f * engine->camera->zoom * WINDOW_WIDTH) +
					engine->camera->x_offset;
			new.y = (y - WINDOW_HEIGHT / 2) /
					(0.5f * engine->camera->zoom * WINDOW_HEIGHT) +
					engine->camera->y_offset;

			int i = julia_calculate(&new, &old, c);

			t_hsv hsv;

			if (i % 361 + engine->camera->hue > 359)
				hsv.h = i % 361 + engine->camera->hue - 359;
			else if (i % 361 + engine->camera->hue < 0)
				hsv.h = 359 + i % 361 + engine->camera->hue;
			else
				hsv.h = i % 361 + engine->camera->hue;
			hsv.s = 1;
			hsv.v = 1 * (i < MAX_ITERATIONS);

			color = set_fractal_color(hsv2rgb(&hsv));
			set_image_pixel(engine->image, x, y, color);
			x++;
		}
		y++;
	}
}
