/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:16:01 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 18:36:21 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_fractal_color(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

t_rgb	hsv2rgb(t_hsv *hsv)
{
	double	r;
	double	g;
	double	b;
	int		i;
	t_rgb	rgb;

	r = 0;
	g = 0;
	b = 0;
	if (hsv->s == 0)
	{
		r = hsv->v;
		g = hsv->v;
		b = hsv->v;
	}
	else
	{
		double f, p, q, t;

		if (hsv->h == 360)
			hsv->h = 0;
		else
			hsv->h /= 60;

		i = (int)trunc(hsv->h);
		f = hsv->h - i;

		p = hsv->v * (1.0 - hsv->s);
		q = hsv->v * (1.0 - (hsv->s * f));
		t = hsv->v * (1.0 - (hsv->s * (1.0 - f)));

		if (i == 0)
		{
			r = hsv->v;
			g = t;
			b = p;
		}
		else if (i == 1)
		{
			r = q;
			g = hsv->v;
			b = p;
		}
		else if (i == 2)
		{
			r = p;
			g = hsv->v;
			b = t;
		}
		else if (i == 3)
		{
			r = p;
			g = q;
			b = hsv->v;
		}
		else if (i == 4)
		{
			r = t;
			g = p;
			b = hsv->v;
		}
		else
		{
			r = hsv->v;
			g = p;
			b = q;
		}
	}

	rgb.r = r * 255;
	rgb.g = g * 255;
	rgb.b = b * 255;
	return (rgb);
}
