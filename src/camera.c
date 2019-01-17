/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:22:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 22:58:17 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_camera(t_engine *engine, float coefficient, int x, int y)
{
	engine->camera->zoom *= (coefficient);
	engine->camera->x_offset = 0.0005f * (WINDOW_WIDTH * 0.5f - x);
	engine->camera->y_offset = 0.0005f * (WINDOW_HEIGHT * 0.5f - y);
	render(engine);
}
