/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:35:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/20 15:28:23 by cmelara-         ###   ########.fr       */
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

int		julia_pixel(t_engine *engine, int x, int y)
{
	t_compl	new;
	t_compl old;
	int i;

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
	return (i);
}

void	julia_camera(t_engine *engine)
{
	engine->camera->xmin = -2.0f;
	engine->camera->xmax = 2.0f;
	engine->camera->ymin = -2.0f;
	engine->camera->ymax = 2.0f;
}
