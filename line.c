/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 22:20:06 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 23:15:57 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rasterize(t_engine *engine, t_line *line, t_point *p1, t_point *p2)
{
	while (1)
	{
		set_image_pixel(engine->image, p1->x, p1->y, p1->color);
		if (p1->x == p2->x && p1->y == p2->y)
			break ;
		line->err2 = 2 * line->err;
		if (line->err2 >= line->dy)
		{
			line->err += line->dy;
			p1->x += line->dirx;
		}
		if (line->err2 <= line->dx)
		{
			line->err += line->dx;
			p1->y += line->diry;
		}
	}
}

void	draw_line(t_engine *engine, t_point p1, t_point p2)
{
	t_line line;

	p1.x = (int)p1.x;
	p1.y = (int)p1.y;
	p2.x = (int)p2.x;
	p2.y = (int)p2.y;
	line.start = p1;
	line.end = p2;
	line.dx = abs(p2.x - p1.x);
	line.dy = -abs(p2.y - p1.y);
	line.dirx = p1.x < p2.x ? 1 : -1;
	line.diry = p1.y < p2.y ? 1 : -1;
	line.err = line.dx + line.dy;
	rasterize(engine, &line, &p1, &p2);
}
