/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:04:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/17 00:06:07 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
************************* FRACTAL VISUALIZER *************************
*/

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720

# include <X11/X.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "mlx_hooks.h"
# include "keymap.h"

typedef struct	s_point
{
	float		x;
	float		y;
	int			color;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
	int			dx;
	int			dy;
	int			dirx;
	int			diry;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_image
{
	void		*image;
	char		*info;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_camera
{
	int			x_offset;
	int			y_offset;
	int			fractal_size;
	float		scale_factor;
}				t_camera;

typedef struct	s_engine
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_mouse		*mouse;
	t_camera	*camera;
}				t_engine;

t_engine		*initialize(char *title);
t_engine		*free_engine(t_engine *engine);

t_image			*delete_image(t_engine *engine, t_image *image);
t_image			*create_image(t_engine *engine);
void			clear_image(t_image *image, int color);
void			set_image_pixel(t_image *image, int x, int y, int color);

int				key_release(int keycode, t_engine *engine);
void			zoom_camera(t_engine *engine);

int				render(t_engine *engine);
void			transform(t_engine *engine, t_point *p1, t_point *p2);

void			draw_line(t_engine *engine, t_point p1, t_point p2);

void			usage_exit(char *msg);
void			error_exit(char *msg);
void			success_exit(t_engine *engine);

#endif
