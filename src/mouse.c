/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:00:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 21:24:31 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		hook_mousedown(int button, int x, int y, t_engine *engine)
{
	(void)x;
	if (button == 4)
	{
		zoom_camera(engine, ZOOM, x, y);
		render(engine);
	}
	else if (button == 5)
	{
		zoom_camera(engine, 1 / ZOOM, x, y);
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
	render(engine);
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
		engine->camera->y_offset += (engine->mouse->prev_y - y) * 0.005f;
		engine->camera->x_offset += (engine->mouse->prev_x - x) * 0.005f;
	}
	else if (engine->mouse->isdown & (1 << 2))
	{
		// mlx->camera->scale += mlx->map->scale_factor * (mlx->mouse->prev_y - y);
		// if (mlx->camera->scale < 1.0f)
		// 	mlx->camera->scale = 1.0f;
		// else if (mlx->camera->scale > 100.0f)
		// 	mlx->camera->scale = 100.0f;
	}
	/*if (engine->mouse->isdown)
		render(engine);*/
	return (0);
}
