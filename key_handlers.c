/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:08:23 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 23:22:41 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_release(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		success_exit(engine);
	if (keycode == KEY_PLUS)
		zoom_camera(engine);
	return (0);
}
