/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:42:23 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/04 12:15:00 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// check norminette for mlx42 functions

void	ft_exit(char *message, int is_success)
{
	if (is_success == 1)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd(message, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Wrong number of arguments!\nEx: ./so_long map.ber", 0);
	check_args(argv[1]);
	
	return (0);
}
