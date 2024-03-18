/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:40:34 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/18 20:56:00 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_collectible_list(t_collect_loc *first)
{
	t_collect_loc	*node;
	t_collect_loc	*temp;

	node = first;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	check_exit(t_all_var *all)
{
	int	i;
	int	p_x;
	int	p_y;
	int	e_x;
	int	e_y;

	i = 0;
	p_x = all->elems->player->instances[0].x;
	p_y = all->elems->player->instances[0].y;
	e_x = all->elems->exit->instances[0].x;
	e_y = all->elems->exit->instances[0].y;
	while (i < (int)(all->elems->collect->count))
	{
		if (all->elems->collect->instances[i].enabled)
			return ;
		i++;
	}
	if (p_x == e_x && p_y == e_y)
	{
		free_collectible_list(all->elems->collect_loc);
		// free(all->elems->collect_loc); //check if it is needed for player
		free(all->elems);
		mlx_terminate(all->window);
		exit (EXIT_SUCCESS);
	}
}
