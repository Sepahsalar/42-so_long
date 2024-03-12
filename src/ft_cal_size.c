/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:32:52 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/12 10:31:50 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_cal_size(t_map *map)
{
	int		monitor_width;
	int		monitor_height;
	mlx_t	*temp;

	temp = mlx_int(100, 100, "temp", true);
	if (!temp)
		ft_exit("Initializing temporary window faild");
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_terminate(temp);

}
