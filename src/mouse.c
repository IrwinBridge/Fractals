/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:00:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 23:28:15 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mousedown(int button, int x, int y, t_engine *engine)
{
	if (button == 4)
	{
		zoom_camera(engine, engine->camera->scale_factor, x, y);
	}
	else if (button == 5)
	{
		zoom_camera(engine, 1 / engine->camera->scale_factor, x, y);
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
		//engine->fractal->c.x = (double)x / (double)WINDOW_WIDTH * 4.0f - 2.0f;
		//engine->fractal->c.y = (double)y / (double)WINDOW_HEIGHT * 4.0f - 2.0f;
		//render(engine);
	}
	return (0);
}
