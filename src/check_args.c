/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/04 11:45:55 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *map, char *extension)
{
	size_t	ext_len;
	size_t	map_len;

	map_len = ft_strlen(map) - 1;
	ext_len = ft_strlen(extension) - 1;
	while (ext_len > 0)
	{
		if (map[map_len] != extension[ext_len])
			ft_exit("Wrong file extension\nEx: map.ber", STDERR_FILENO);
		map_len--;
		ext_len--;
	}
}

void	check_args(char *argv)
{
	int	fd;

	check_extension(argv, ".ber");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("Opening file failed", 0);
	
}