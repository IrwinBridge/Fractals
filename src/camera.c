/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:22:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/20 14:12:07 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	zoom(t_camera *cam, float coeff, int x, int y)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (cam->xmax - cam->xmin) * cam->zoom;
	h = (cam->ymax - cam->ymin) * cam->zoom;
	nw = (cam->xmax - cam->xmin) * (cam->zoom * coeff);
	nh = (cam->ymax - cam->ymin) * (cam->zoom * coeff);
	cam->zoom *= coeff;
	cam->x_offset -= ((double)x / WINDOW_WIDTH) * (nw - w);
	cam->y_offset -= ((double)y / WINDOW_HEIGHT) * (nh - h);
}

void	transform(t_camera *cam, t_compl *new, int x, int y)
{
	new->r = ((double)x / (double)WINDOW_WIDTH)
			* (cam->xmax - cam->xmin)
			* cam->zoom
			+ cam->xmin
			+ cam->x_offset;
	new->i = ((double)y / (double)WINDOW_HEIGHT)
			* (cam->ymax - cam->ymin)
			* cam->zoom
			+ cam->ymin
			+ cam->y_offset;
}
