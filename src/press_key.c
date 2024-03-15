/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:41:14 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 16:00:15 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_wall(mlx_image_t *player, mlx_image_t *wall, int i, char c)
{
	int	p_x;
	int	p_y;
	int	w_x;
	int	w_y;

	p_x = player->instances[0].x;
	p_y = player->instances[0].y;
	w_x = wall->instances[i].x;
	w_y = wall->instances[i].y;
	if (c == 'U' && p_x == w_x && (p_y == w_y + (int)(player->height)))
		return (0);
	if (c == 'D' && p_x == w_x && (p_y == w_y - (int)(player->height)))
		return (0);
	if (c == 'L' && p_y == w_y && (p_x == w_x + (int)(player->width)))
		return (0);
	if (c == 'R' && p_y == w_y && (p_x == w_x - (int)(player->width)))
		return (0);
	return (i + 1);
}

static int	near_wall(t_all_var *all, char c)
{
	int	i;

	i = 0;
	while (i < (int)(all->elems->wall->count))
	{
		if (!check_wall(all->elems->player, all->elems->wall, i, c))
			return (0);
		i++;
	}
	return (1);
}

static void	move_con(t_all_var *all, char c)
{
	if (c == 'U')
	{
		all->elems->player->instances[0].y -= all->elems->player->height;
		all->elems->player_loc.y += -1;
	}
	else if (c == 'D')
	{
		all->elems->player->instances[0].y += all->elems->player->height;
		all->elems->player_loc.y += 1;
	}
	else if (c == 'L')
	{
		all->elems->player->instances[0].x -= all->elems->player->width;
		all->elems->player_loc.x += -1;
	}
	else
	{
		all->elems->player->instances[0].x += all->elems->player->width;
		all->elems->player_loc.x += 1;
	}
}

static void	move(void *param, char c)
{
	t_all_var	*all;

	all = (t_all_var *)param;
	if (near_wall(all, c))
	{
		(*all->move_count)++;
		ft_printf("Movements: %d\n", (*all->move_count));
		move_con(all, c);
		check_collectible(all);
		// check_exit(all);
	}
}

void	press_key(mlx_key_data_t keydata, void *param)
{
	//test MLX_REPEAT
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_PRESS)
		move(param, 'U');
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_PRESS)
		move(param, 'D');
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_PRESS)
		move(param, 'L');
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_PRESS)
		move(param, 'R');
}
