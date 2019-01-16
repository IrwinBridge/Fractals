/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:31:17 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 23:32:27 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	transform(t_engine *engine, t_point *p1, t_point *p2)
{
	p1->x *= engine->camera->scale;
	p1->y *= engine->camera->scale;
	p2->x *= engine->camera->scale;
	p2->y *= engine->camera->scale;
}
