/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:08:23 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 00:03:48 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_release(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		success_exit(engine);
	if (keycode == KEY_PLUS)
	{
		engine->camera->fractal_size *= engine->camera->scale_factor;
		render(engine);
	}
	if (keycode == KEY_MINUS)
	{
		engine->camera->fractal_size /= engine->camera->scale_factor;
		render(engine);
	}
	return (0);
}
