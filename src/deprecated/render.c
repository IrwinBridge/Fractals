/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:24:04 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/20 15:55:48 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
************************* RENDERING PART OF THE SCREEN ************************
*/
#include <time.h>
#include <stdio.h>

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
			julia_pixel(((t_thread *)thread)->engine, x ,y);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

int		render(t_engine *engine)
{
	clock_t start, end;
    double cpu_time_used;
	start = clock();

	// int			i;
	// pthread_t 	tid[THREADS];
	//
	// i = 0;
	// while (i < THREADS)
	// {
	// 	engine->threads[i].id = i;
	// 	engine->threads[i].engine = engine;
	// 	pthread_create(&tid[i], NULL, render_thread, &(engine->threads[i]));
	// 	i++;
	// }
	// i = 0;
	// while (i < THREADS)
	// {
	// 	pthread_join(tid[i], NULL);
	// 	i++;
	// }
	// mlx_put_image_to_window(engine->mlx, engine->window,
	// 						engine->image->image, 0, 0);

	int color;
	int pixel = 0;
	int screen_size = WINDOW_WIDTH * WINDOW_HEIGHT;

	while (pixel < screen_size)
	{
		color = julia_pixel(engine, pixel % WINDOW_WIDTH, pixel / WINDOW_WIDTH);
		*(int *)(engine->image->info + (pixel * engine->image->bpp)) = color;
		pixel++;
	}

	mlx_put_image_to_window(engine->mlx, engine->window,
							engine->image->image, 0, 0);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", cpu_time_used);

	return (0);
}
