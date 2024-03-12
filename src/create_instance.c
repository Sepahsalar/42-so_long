/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:17:35 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/12 15:34:04 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_instance(mlx_t *window, t_elem *elements, t_map *map, char *arg)
{
	mlx_image_t	*bg;

	bg = elements->empty;
	if (mlx_image_to_window(window, bg, 0, 0) == -1)
	{
		free(elements);
		mlx_terminate(window);
		ft_exit("Allocating memory failed");
	}
	//add instance of elements
}
