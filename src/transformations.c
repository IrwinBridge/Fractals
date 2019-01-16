/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:31:17 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 00:03:57 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	transform(t_engine *engine, t_point *p1, t_point *p2)
{
	p1->x = WINDOW_WIDTH / 2 - engine->camera->fractal_size;
	p1->y = WINDOW_HEIGHT / 2 + engine->camera->fractal_size;
	p2->x = WINDOW_WIDTH / 2 - engine->camera->fractal_size;
	p2->y = WINDOW_HEIGHT / 2 - engine->camera->fractal_size;
}
