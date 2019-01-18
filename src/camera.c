/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:22:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 22:37:34 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

// void		zoom(int x, int y, t_viewport *v, double z)
// {
// 	double w;
// 	double h;
// 	double nw;
// 	double nh;
//
// 	w = (v->xmax - v->xmin) * (v->zoom);
// 	h = (v->ymax - v->ymin) * (v->zoom);
// 	nw = (v->xmax - v->xmin) * (v->zoom * z);
// 	nh = (v->ymax - v->ymin) * (v->zoom * z);
// 	v->zoom *= z;
// 	v->offx -= ((double)x / WIN_WIDTH) * (nw - w);
// 	v->offy -= ((double)y / WIN_HEIGHT) * (nh - h);
// }

void	zoom_camera(t_engine *engine, float coefficient, int x, int y)
{
	// float	sx;
	// float	dx;
	// float	sy;
	// float	dy;
	double	w;
	double	h;
	double	nw;
	double	nh;

	// sx = engine->camera->x_offset + ((float)x - (float)WINDOW_WIDTH / 2);
	// dx = sx * engine->camera->zoom;
	//
	// sy = engine->camera->y_offset + ((float)y - (float)WINDOW_HEIGHT / 2);
	// dy = sy * engine->camera->zoom;
	//
	// engine->camera->x_offset = (float)(dx - sx);
	// engine->camera->y_offset = (float)(dy - sy);
	w = WINDOW_WIDTH * engine->camera->zoom;
	h = WINDOW_HEIGHT * engine->camera->zoom;
	nw = WINDOW_WIDTH * engine->camera->zoom * coefficient;
	nh = WINDOW_HEIGHT * engine->camera->zoom * coefficient;
	engine->camera->zoom *= coefficient;
	engine->camera->x_offset += ((double)x / (double)WINDOW_WIDTH) * (nw - w);
	engine->camera->y_offset += ((double)y / (double)WINDOW_HEIGHT) * (nh - h);
	render(engine);
}

void	transform(t_engine *engine, t_point *new, int x, int y)
{
	new->x = 1.5f * (x - WINDOW_WIDTH / 2)
			/ (engine->camera->zoom * WINDOW_WIDTH / 2)
			+ 1.5f * (engine->camera->x_offset)
			/ (engine->camera->zoom * WINDOW_WIDTH / 2);
	new->y = (y - WINDOW_HEIGHT * 0.5f)
			/ (engine->camera->zoom * WINDOW_HEIGHT / 2)
			+ (engine->camera->y_offset)
			/ (engine->camera->zoom * WINDOW_HEIGHT / 2);
}

// t_complex	screen_to_complex(int x, int y, t_viewport *v)
// {
// 	t_complex	p;
//
// 	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
// 		+ v->xmin + v->offx;
// 	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
// 		+ v->ymin + v->offy;
// 	return (p);
// }
