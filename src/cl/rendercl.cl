__kernel void	render(__global char *img_buff, t_engine *engine)
{
	unsigned int	pixel;
	int				screen_size;
	int				color;

	pixel = get_global_id(0);
	screen_size = WINDOW_WIDTH * WINDOW_HEIGHT;
	while (pixel < screen_size)
	{
		color = julia_pixel(engine, pixel % WINDOW_WIDTH, pixel / WINDOW_WIDTH);
		*(int *)(img_buff + (pixel * engine->image->bpp)) = color;
		pixel++;
	}
}
