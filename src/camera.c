/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:22:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 18:12:16 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_camera(t_engine *engine, float coefficient, int x, int y)
{
	engine->camera->zoom *= (coefficient);
	engine->camera->x_offset += (WINDOW_WIDTH / 2 - x) * engine->camera->zoom;
	engine->camera->y_offset += (WINDOW_HEIGHT / 2 - y) * engine->camera->zoom;
	render(engine);
}

void	transform(t_engine *engine, t_point *new, int x, int y)
{
	new->x = 1.5f * (x - WINDOW_WIDTH * 0.5f)
			/ (engine->camera->zoom * WINDOW_WIDTH * 0.5f)
			- 1.5f * (engine->camera->x_offset)
			/ (engine->camera->zoom * WINDOW_WIDTH * 0.5f);
	new->y = (y - WINDOW_HEIGHT * 0.5f)
			/ (engine->camera->zoom * WINDOW_HEIGHT * 0.5f)
			- (engine->camera->y_offset)
			/ (engine->camera->zoom * WINDOW_HEIGHT * 0.5f);
}
