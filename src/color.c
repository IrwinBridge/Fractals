/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:16:01 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/22 00:16:56 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_fractal_color(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

void	vec_eq(t_drgb *drgb, double r, double g, double b)
{
	drgb->r = r;
	drgb->g = g;
	drgb->b = b;
}

void	to_rgb_helper(t_hsv *hsv, t_drgb *drgb, t_temp *temp, int i)
{
	temp->f = hsv->h - i;
	temp->p = hsv->v * (1.0 - hsv->s);
	temp->q = hsv->v * (1.0 - (hsv->s * temp->f));
	temp->t = hsv->v * (1.0 - (hsv->s * (1.0 - temp->f)));
	if (i == 0)
		vec_eq(drgb, hsv->v, temp->t, temp->p);
	else if (i == 1)
		vec_eq(drgb, temp->q, hsv->v, temp->p);
	else if (i == 2)
		vec_eq(drgb, temp->p, hsv->v, temp->t);
	else if (i == 3)
		vec_eq(drgb, temp->p, temp->q, hsv->v);
	else if (i == 4)
		vec_eq(drgb, temp->t, temp->p, hsv->v);
	else
		vec_eq(drgb, hsv->v, temp->p, temp->q);
}

t_rgb	hsv2rgb(t_hsv *hsv)
{
	t_drgb	drgb;
	t_temp	temp;
	int		i;
	t_rgb	rgb;

	drgb.r = 0;
	drgb.g = 0;
	drgb.b = 0;
	if (hsv->s == 0)
	{
		drgb.r = hsv->v;
		drgb.g = hsv->v;
		drgb.b = hsv->v;
	}
	else
	{
		hsv->h = (hsv->h == 360) ? 0 : hsv->h / 60;
		i = (int)trunc(hsv->h);
		to_rgb_helper(hsv, &drgb, &temp, i);
	}
	rgb.r = drgb.r * 255;
	rgb.g = drgb.g * 255;
	rgb.b = drgb.b * 255;
	return (rgb);
}

t_hsv	*get_i_color(t_engine *engine, int i)
{
	t_hsv *hsv;

	hsv = (t_hsv *)malloc(sizeof(t_hsv));
	if (i % 361 + engine->camera->hue > 359)
		hsv->h = i % 361 + engine->camera->hue - 359;
	else if (i % 361 + engine->camera->hue < 0)
		hsv->h = 359 + i % 361 + engine->camera->hue;
	else
		hsv->h = i % 361 + engine->camera->hue;
	hsv->s = 1;
	hsv->v = 1 * (i < engine->fractal->max_iterations);
	return (hsv);
}
