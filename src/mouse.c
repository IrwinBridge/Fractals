/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:00:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 19:08:32 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mousedown(int button, int x, int y, t_engine *engine)
{
	if (button == 4)
	{
		zoom_camera(engine, engine->camera->scale_factor, x, y);
		render(engine);
	}
	else if (button == 5)
	{
		zoom_camera(engine, 1 / engine->camera->scale_factor, x, y);
		render(engine);
	}
	if (y < 0)
		return (0);
	engine->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_engine *engine)
{
	(void)x;
	(void)y;
	engine->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_engine *engine)
{
	engine->mouse->prev_x = engine->mouse->x;
	engine->mouse->prev_y = engine->mouse->y;
	engine->mouse->x = x;
	engine->mouse->y = y;
	if (engine->mouse->isdown & (1 << 1))
	{
	}
	else if (engine->mouse->isdown & (1 << 2))
	{
	}
	else
	{
		// TODO: change for if no button is down
		//engine->fractal->c.x = (WINDOW_WIDTH - engine->mouse->x) / WINDOW_WIDTH * 2;
	}
	return (0);
}
