/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:21:12 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/21 23:24:05 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(t_engine *engine, int x, int y)
{
	if (engine->fractal->name == JULIA)
		julia_pixel(engine, x, y);
	else if (engine->fractal->name == MANDELBROT)
		mandelbrot_pixel(engine, x, y);
	else if (engine->fractal->name == BURNINGSHIP)
		burningship_pixel(engine, x, y);
}
