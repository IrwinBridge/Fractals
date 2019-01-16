/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:24:04 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 00:03:55 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_levi(t_engine *engine, int n, t_point p1, t_point p2, float a)
{
	t_point p3;

	if (!n)
		draw_line(engine, p1, p2);
	else
	{
		p3.x = (cos(a) * ((p2.x - p1.x) * cos(a) - (p2.y - p1.y) * sin(a))) + p1.x;
		p3.y = (cos(a) * ((p2.x - p1.x) * sin(a) + (p2.y - p1.y) * cos(a))) + p1.y;
		p3.color = 0;
		draw_levi(engine, n - 1, p1, p3, a);
		draw_levi(engine, n - 1, p3, p2, a);
	}
}

int		render(t_engine *engine)
{
	t_point p1;
	t_point p2;
	float	a;

	clear_image(engine->image, 0xFFFFFF);

	a = 45.0f * M_PI / 180.0f;
	p1.color = 0;
	p2.color = 0;
	transform(engine, &p1, &p2);
	draw_levi(engine, 17, p1, p2, a);

	mlx_put_image_to_window(engine->mlx, engine->window,
							engine->image->image, 0, 0);
	return (0);
}
