/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:42:23 by asohrabi          #+#    #+#             */
/*   Updated: 2024/02/28 10:29:37 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer,
// it will be four bytes for four channels.
#define BPP sizeof(int32_t)

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	// Init mlx with a canvas size of 256x256
	// and the ability to resize the window.
	mlx = mlx_init(256, 256, "./so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// Create a 128x128 image.
	img = mlx_new_image(mlx, 128, 128);
	// Set the channels of each pixel in our image
	// to the maximum byte value of 255. 
	ft_memset(img->pixels, 255, img->width * img->height * BPP);
	// Draw the image at coordinate (0, 0).
	mlx_image_to_window(mlx, img, 0, 0);
	// Run the main loop and terminate on quit.  
	mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


