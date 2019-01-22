/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:24:04 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/21 23:24:22 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*render_thread(void *thread)
{
	int x;
	int y;

	y = WINDOW_HEIGHT / THREADS * ((t_thread *)thread)->id;
	while (y < WINDOW_HEIGHT / THREADS * (((t_thread *)thread)->id + 1))
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			choose_fractal(((t_thread *)thread)->engine, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

int		render(t_engine *engine)
{
	int			i;
	pthread_t	tid[THREADS];

	i = 0;
	while (i < THREADS)
	{
		engine->threads[i].id = i;
		engine->threads[i].engine = engine;
		pthread_create(&tid[i], NULL, render_thread, &(engine->threads[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	mlx_put_image_to_window(engine->mlx, engine->window,
							engine->image->image, 0, 0);
	return (0);
}
