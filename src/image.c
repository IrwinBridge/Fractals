/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:55:47 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 18:37:52 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*delete_image(t_engine *engine, t_image *image)
{
	if (image)
	{
		if (image->image)
			mlx_destroy_image(engine->mlx, image->image);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

t_image		*create_image(t_engine *engine)
{
	t_image		*image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->image = mlx_new_image(engine->mlx,
									   WINDOW_WIDTH, WINDOW_HEIGHT)))
		return (delete_image(engine, image));
	image->info = mlx_get_data_addr(image->image, &image->bpp,
									&image->stride, &image->endian);
	image->bpp /= 8;
	return (image);
}

void		clear_image(t_image *image, int color)
{
	int i;

	i = 0;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT - 1)
	{
		*(int *)(image->info + (i * image->bpp)) = color;
		i++;
	}
}

void		set_image_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	*(int *)(image->info + ((x + y * WINDOW_WIDTH) * image->bpp)) = color;
}
