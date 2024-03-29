/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:32:52 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/19 12:59:12 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	cal_size_helper(t_map *map, float ratio)
{
	map->image_width = round(ratio);
	map->image_height = round(ratio);
	map->window_width = round(map->image_width * map->line_width);
	map->window_height = round(map->image_height * map->line_count);
}

void	cal_size(t_map *map)
{
	int		monitor_width;
	int		monitor_height;
	mlx_t	*temp;
	float	ratio_width;
	float	ratio;

	temp = mlx_init(10, 10, "temp", true);
	if (!temp)
		ft_exit("Initializing temporary window faild");
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_terminate(temp);
	monitor_width = round(monitor_width * 0.9);
	monitor_height = round(monitor_height * 0.9);
	ratio_width = monitor_width / map->line_width;
	if (ratio_width < 10)
		ft_exit("Too big width for this monitor");
	ratio = monitor_height / map->line_count;
	if (ratio < 10)
		ft_exit("Too big height for this monitor");
	if (ratio_width < ratio)
		ratio = ratio_width;
	if (ratio > 80)
		ratio = 80;
	cal_size_helper(map, ratio);
}
