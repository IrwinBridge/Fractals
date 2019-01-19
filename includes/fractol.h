/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:04:49 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/20 00:21:55 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
************************* FRACTAL VISUALIZER *************************
*/

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	800

# define THREADS		4

# include <X11/X.h>
# include <math.h>
# include <CL/opencl.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "mlx_hooks.h"
# include "keymap.h"

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct	s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct	s_point
{
	double		x;
	double		y;
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

typedef struct	s_fractal
{
	t_point		c;
	int			deform;
	int			max_iterations;
}				t_fractal;

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
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		x_offset;
	double		y_offset;
	double		zoom;
	double		scale_factor;
	double		hue;
}				t_camera;

typedef struct	s_thread
{
	int			id;
	void		*engine;
}				t_thread;

typedef struct	s_engine
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_mouse		*mouse;
	t_camera	*camera;
	t_fractal	*fractal;
	t_thread	threads[THREADS];
}				t_engine;

t_engine		*initialize(char *title);
t_engine		*free_engine(t_engine *engine);

t_image			*delete_image(t_engine *engine, t_image *image);
t_image			*create_image(t_engine *engine);
void			clear_image(t_image *image, int color);
void			set_image_pixel(t_image *image, int x, int y, int color);

int				key_release(int keycode, t_engine *engine);
int				hook_mousedown(int button, int x, int y, t_engine *engine);
int				hook_mouseup(int button, int x, int y, t_engine *engine);
int				hook_mousemove(int x, int y, t_engine *engine);

int				render(t_engine *engine);

void			zoom(t_camera *cam, float coeff, int x, int y);
void			transform(t_camera *cam, t_point *new, int x, int y);

void			julia_pixel(t_engine *engine, int x, int y);
void			julia_camera(t_engine *engine);

int				set_fractal_color(t_rgb rgb);
t_rgb			hsv2rgb(t_hsv *hsv);

void			usage_exit(char *msg);
void			error_exit(char *msg);
void			success_exit(t_engine *engine);

#endif
