/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:38:26 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 00:04:00 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_engine	*free_engine(t_engine *engine)
{
	if (engine->window)
		mlx_destroy_window(engine->mlx, engine->window);
	if (engine->image)
		delete_image(engine, engine->image);
	if (engine->mouse)
		ft_memdel((void **)&engine->mouse);
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
		!(engine->camera = ft_memalloc(sizeof(t_camera))))
		return (free_engine(engine));
	return (engine);
}
