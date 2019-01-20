/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:11:56 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/20 17:21:21 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

#define PROGRAM_FILE "render.cl"
#define KERNEL_FUNC "render"
#define WG_SIZE 256 // Workgroup size

/*
**	OpenCL initialization code
*/

cl_device_id	create_device(t_engine *engine)
{
	cl_platform_id	platform;
	cl_device_id	device;
	int				err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err < 0)
	{
		ft_putendl("Couldn't identify a platform!");
		printf("%d\n", err);
		success_exit(engine);
	}

	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (err == CL_DEVICE_NOT_FOUND)
		err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &device, NULL);
	if (err < 0)
	{
		ft_putendl("Can't access any device!");
		success_exit(engine);
	}
	return (device);
}

void	init_cl(t_engine *engine)
{
	/* OpenCL structures */
	cl_device_id device;

	device = create_device(engine);
	(void)device;
}
