/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:38:26 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/19 17:48:03 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setting(t_engine *engine)
{
	engine->camera->x_offset = 0.0f;
	engine->camera->y_offset = 0.0f;
	engine->camera->zoom = 1.0f;
	engine->camera->scale_factor = 1.05f;
	engine->camera->hue = 0.0f;
	engine->fractal->c.x = -0.7f;
	engine->fractal->c.y = 0.27015f;
	engine->fractal->deform = 0;
	engine->fractal->max_iterations = 100;
	julia_camera(engine);
}

t_engine	*free_engine(t_engine *engine)
{
	if (engine->window)
		mlx_destroy_window(engine->mlx, engine->window);
	if (engine->image)
		delete_image(engine, engine->image);
	if (engine->mouse)
		ft_memdel((void **)&engine->mouse);
	if (engine->fractal)
		ft_memdel((void **)&engine->fractal);
	if (engine->camera)
		ft_memdel((void **)&engine->camera);
	ft_memdel((void **)&engine->mlx);
	ft_memdel((void **)&engine);
	return (NULL);
}

t_engine	*initialize(char *title)
{
	t_engine	*engine;

	if (!(engine = ft_memalloc(sizeof(t_engine))))
		return (NULL);
	if (!(engine->mlx = mlx_init())						||
		!(engine->window = mlx_new_window(engine->mlx,
										  WINDOW_WIDTH,
										  WINDOW_HEIGHT,
										  title))		||
		!(engine->image = create_image(engine))			||
		!(engine->mouse = ft_memalloc(sizeof(t_mouse))) ||
		!(engine->fractal = ft_memalloc(sizeof(t_fractal))) ||
		!(engine->camera = ft_memalloc(sizeof(t_camera))))
		return (free_engine(engine));
	setting(engine);
	return (engine);
}
