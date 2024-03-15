/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:42:23 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 15:23:21 by asohrabi         ###   ########.fr       */
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
	t_all_var	all;
	int			count;

	count = 0;
	all.move_count = &count;
	if (argc != 2)
		ft_exit("Wrong number of arguments!\nEx: ./so_long map.ber");
	all.map = check_args(argv[1]);
	cal_size(all.map);
	all.window = mlx_init(all.map->window_width, all.map->window_height,
			argv[0], false);
	if (!all.window)
		ft_exit("Initializing window failed");
	all.elems = create_elements(all.window, all.map);
	if (!all.elems)
	{
		mlx_terminate(all.window);
		ft_exit("Allocating memory failed");
	}
	create_instance(all.window, all.elems, all.map, argv[1]);
	mlx_key_hook(all.window, &press_key, &all);
	mlx_loop(all.window);
	//handle terminate and freeing stuff
	return (0);
}
