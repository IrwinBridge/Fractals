/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:08:23 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/21 23:42:45 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		camera_comtrol(int keycode, t_engine *engine)
{
	if (keycode == KEY_PLUS)
		engine->camera->zoom *= engine->camera->scale_factor;
	else if (keycode == KEY_MINUS)
		engine->camera->zoom /= engine->camera->scale_factor;
	else if (keycode == KEY_UP)
		engine->camera->y_offset -= (100.0f / (double)WINDOW_HEIGHT)
									* engine->camera->zoom;
	else if (keycode == KEY_DOWN)
		engine->camera->y_offset += (100.0f / (double)WINDOW_HEIGHT)
									* engine->camera->zoom;
	else if (keycode == KEY_RIGHT)
		engine->camera->x_offset += (100.0f / (double)WINDOW_WIDTH)
									* engine->camera->zoom;
	else if (keycode == KEY_LEFT)
		engine->camera->x_offset -= (100.0f / (double)WINDOW_WIDTH)
									* engine->camera->zoom;
	else if (keycode == KEY_B_O)
		engine->camera->hue -= 2.0f;
	else if (keycode == KEY_B_C)
		engine->camera->hue += 2.0f;
	else
		return (0);
	return (1);
}

int		fractal_control(int keycode, t_engine *engine)
{
	if (keycode == KEY_MUL)
		engine->fractal->max_iterations *= 2;
	else if (keycode == KEY_DIV)
		engine->fractal->max_iterations /= 2;
	else if (keycode == KEY_NUM8)
		engine->fractal->c.i += 0.001f;
	else if (keycode == KEY_NUM2)
		engine->fractal->c.i -= 0.001f;
	else if (keycode == KEY_NUM4)
		engine->fractal->c.r -= 0.001f;
	else if (keycode == KEY_NUM6)
		engine->fractal->c.r += 0.001f;
	else
		return (0);
	return (1);
}

int		key_release(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		success_exit(engine);
	if (camera_comtrol(keycode, engine))
		render(engine);
	else if (fractal_control(keycode, engine))
		render(engine);
	else if (keycode == KEY_NUM0)
	{
		engine->camera->zoom = 1.0f;
		engine->camera->x_offset = 0.0f;
		engine->camera->y_offset = 0.0f;
		engine->fractal->c.r = -0.7f;
		engine->fractal->c.i = 0.27015f;
		engine->fractal->max_iterations = 100;
		render(engine);
	}
	return (0);
}
