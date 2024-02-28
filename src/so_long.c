/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:42:23 by asohrabi          #+#    #+#             */
/*   Updated: 2024/02/28 16:01:26 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <string.h>

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(500, 500, "title", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 100, 100);
	if (!img)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	if (mlx_image_to_window(mlx, img, 200, 200) < 0)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
