/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:08:23 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 22:39:04 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_release(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		success_exit(engine);
	if (keycode == KEY_PLUS)
	{
		engine->camera->zoom *= engine->camera->scale_factor;
		render(engine);
	}
	if (keycode == KEY_MINUS)
	{
		engine->camera->zoom /= engine->camera->scale_factor;
		render(engine);
	}

	if (keycode == KEY_UP)
	{
		engine->camera->y_offset -= 0.1f;
		render(engine);
	}
	if (keycode == KEY_DOWN)
	{
		engine->camera->y_offset += 0.1f;
		render(engine);
	}
	if (keycode == KEY_RIGHT)
	{
		engine->camera->x_offset += 0.1f;
		render(engine);
	}
	if (keycode == KEY_LEFT)
	{
		engine->camera->x_offset -= 0.1f;
		render(engine);
	}

	if (keycode == KEY_B_O)
	{
		engine->camera->hue -= 2.0f;
		render(engine);
	}
	if (keycode == KEY_B_C)
	{
		engine->camera->hue += 2.0f;
		render(engine);
	}
	return (0);
}
