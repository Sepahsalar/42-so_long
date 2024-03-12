/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:42:23 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/08 10:31:56 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_exit(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	mlx_t	*window;
	t_map	*map;

	if (argc != 2)
		ft_exit("Wrong number of arguments!\nEx: ./so_long map.ber");
	map = check_args(argv[1]);
	// I should grab the size of window here
	ft_cal_size(map);
	window = mlx_init(map->line_width, map->line_count, argv[0], true);
	mlx_loop(window);
	return (0);
}
