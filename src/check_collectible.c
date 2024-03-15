/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:58:06 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 17:07:12 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	change_collect_list(t_collect_loc *collectible, int c_x, int c_y)
{
	t_collect_loc	*node;

	node = collectible;
	while (node)
	{
		ft_printf("hi3\n");
		if (((int)(node->x) == c_x) && (node->y == c_y))
		{
			ft_printf("hi4\n");
			node->enabled = 0;
			ft_printf("hi5\n");
			break ;
		}
		ft_printf("hi6\n");
		node = node->next;
		ft_printf("hi7\n");
	}
}

void	check_collectible(t_all_var	*all)
{
	int	i;
	int	p_x;
	int	p_y;
	int	c_x;
	int	c_y;

	i = 0;
	while (i < (int)(all->elems->collect->count))
	{
		p_x = all->elems->player->instances[0].x;
		p_y = all->elems->player->instances[0].y;
		c_x = all->elems->collect->instances[i].x;
		c_y = all->elems->collect->instances[i].y;
		if (p_x == c_x && p_y == c_y)
		{
			change_collect_list(all->elems->collect_loc,
				(c_x / (all->elems->collect->width)),
				(c_y / (all->elems->collect->height)));
			all->elems->collect->instances[i].enabled = 0;
		}
		i++;
	}
}
