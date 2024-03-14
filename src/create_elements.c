/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:45:45 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/14 19:55:02 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_texture_t	*load_image(mlx_t *window, char c)
{
	mlx_texture_t	*texture;

	if (c == '1')
		texture = mlx_load_png("./textures/wall.png");
	else if (c == 'P')
		texture = mlx_load_png("./textures/player.png");
	else if (c == 'C')
		texture = mlx_load_png("./textures/collectible.png");
	else
		texture = mlx_load_png("./textures/exit.png");
	if (!texture)
	{
		mlx_terminate(window);
		ft_exit("Allocating memory failed");
	}
	return (texture);
}

static mlx_image_t	*image(mlx_t *window, int i_width, int i_height, char c)
{
	mlx_texture_t	*texture;
	mlx_image_t		*picture;

	texture = load_image(window, c);
	picture = mlx_texture_to_image(window, texture);
	if (!picture)
	{
		mlx_terminate(window);
		ft_exit("Allocating memory failed");
	}
	mlx_delete_texture(texture);
	if (!mlx_resize_image(picture, i_width, i_height))
	{
		mlx_terminate(window);
		ft_exit("Resizing pictures failed");
	}
	return (picture);
}

static int	color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static mlx_image_t	*background(mlx_t *window, int w_width, int w_height)
{
	mlx_image_t	*bg;
	int			i;
	int			j;

	i = 0;
	j = 0;
	bg = mlx_new_image(window, w_width, w_height);
	if (!bg)
	{
		mlx_terminate(window);
		ft_exit("Allocating memory failed");
	}
	while (i < w_width)
	{
		j = 0;
		while (j < w_height)
		{
			mlx_put_pixel(bg, i, j, color(15, 125, 205, 255));
			j++;
		}
		i++;
	}
	return (bg);
}

t_elem	*create_elements(mlx_t *window, t_map *map)
{
	t_elem	*elements;

	elements = malloc(sizeof(t_elem));
	if (!elements)
	{
		mlx_terminate(window);
		ft_exit("Allocating memory failed");
	}
	elements->empty = background(window, map->window_width, map->window_height);
	elements->wall = image(window, map->image_width, map->image_height, '1');
	elements->player = image(window, map->image_width, map->image_height, 'P');
	elements->collect = image(window, map->image_width, map->image_height, 'C');
	elements->exit = image(window, map->image_width, map->image_height, 'E');
	return (elements);
}
