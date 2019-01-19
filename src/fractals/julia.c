/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:35:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/19 13:36:20 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_hsv	*get_julia_color(t_engine *engine, int i)
{
	t_hsv *hsv;

	hsv = (t_hsv *)malloc(sizeof(t_hsv));
	if (i % 361 + engine->camera->hue > 359)
		hsv->h = i % 361 + engine->camera->hue - 359;
	else if (i % 361 + engine->camera->hue < 0)
		hsv->h = 359 + i % 361 + engine->camera->hue;
	else
		hsv->h = i % 361 + engine->camera->hue;
	hsv->s = 1;
	hsv->v = 1 * (i < engine->fractal->max_iterations);
	return (hsv);
}

int		julia_pixel(t_engine *engine, t_point *new, t_point *old, t_point c)
{
	int i;

	i = 0;
	while (i < engine->fractal->max_iterations)
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
	t_point	old;
	t_point	new;
	int		i;
	int		x;
	int		y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			transform(engine->camera, &new, x, y);
			i = julia_pixel(engine, &new, &old, engine->fractal->c);
			set_image_pixel(engine->image, x, y,
					set_fractal_color(hsv2rgb(get_julia_color(engine, i))));
			x++;
		}
		y++;
	}
}

void	julia_camera(t_engine *engine)
{
	engine->camera->xmin = -2.0f;
	engine->camera->xmax = 2.0f;
	engine->camera->ymin = -2.0f;
	engine->camera->ymax = 2.0f;
}
