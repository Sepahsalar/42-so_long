/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:17:35 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/14 18:03:54 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_instance(mlx_t *window, t_elem *elements, t_map *map, char *arg)
{
	int			fd;
	mlx_image_t	*image;
	t_loc		loc;

	image = elements->empty;
	if (mlx_image_to_window(window, image, 0, 0) == -1)
	{
		free(elements);
		mlx_terminate(window);
		ft_exit("Allocating memory failed");
	}
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		free(elements);
		mlx_terminate(window);
		ft_exit("Opening map failed");
	}
	loc.x = 0;
	loc.y = 0;
	loc.c = '\0';
	while (read(fd, &loc.c, 1))
	{
		if (loc.c == '\n')
		{
			loc.x = 0;
			loc.y += map->image_height;
		}
		else
		{
			// if (loc.c != 'P' && loc.c != '0')
			if (loc.c != '0')
			{
				if (loc.c == '1')
					image = elements->wall;
				else if (loc.c == 'P')
					image = elements->player;
				else if (loc.c == 'C')
					image = elements->collect;
				else
					image = elements->exit;
				if (mlx_image_to_window(window, image, loc.x, loc.y) == -1)
				{
					free(elements);
					mlx_terminate(window);
					ft_exit("Making instance failed");
				}
			}
			loc.x += map->image_width;
		}
	}
	close(fd);
}
