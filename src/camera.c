/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:22:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 23:50:38 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

void	zoom_camera(t_engine *engine, float coefficient, int x, int y)
{
	float	sx;
	float	dx;
	float	sy;
	float	dy;

	engine->camera->zoom *= coefficient;

	sx = engine->camera->x_offset + ((float)x - (float)WINDOW_WIDTH / 2);
	dx = sx * engine->camera->zoom;

	sy = engine->camera->y_offset + ((float)y - (float)WINDOW_HEIGHT / 2);
	dy = sy * engine->camera->zoom;

	engine->camera->x_offset = (float)(dx - sx);
	engine->camera->y_offset = (float)(dy - sy);

	engine->camera->x_offset = 1.5f * (engine->camera->x_offset)
								/ (engine->camera->zoom * WINDOW_WIDTH / 2);
	engine->camera->y_offset = (engine->camera->y_offset)
								/ (engine->camera->zoom * WINDOW_HEIGHT / 2);
	render(engine);
}

void	transform(t_engine *engine, t_point *new, int x, int y)
{
	new->x = 1.5f * (x - WINDOW_WIDTH / 2)
			/ (engine->camera->zoom * WINDOW_WIDTH / 2)
			+ engine->camera->x_offset;
	new->y = (y - WINDOW_HEIGHT / 2)
			/ (engine->camera->zoom * WINDOW_HEIGHT / 2)
			+ engine->camera->y_offset;
}
