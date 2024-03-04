/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/04 17:48:01 by asohrabi         ###   ########.fr       */
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
			ft_exit("Wrong file extension\nEx: map.ber");
		map_len--;
		ext_len--;
	}
}

static char	*ft_read(int fd)
{
	char	buf[51];
	int		i;
	char	*map;

	i = 1;
	map = ft_calloc(1, 1);
	if (!map)
		ft_exit("Allocating memory failed");
	while (i != 0)
	{
		i = read(fd, buf, 50);
		if (i == -1)
			ft_exit("Reading file failed");
		buf[i] = '\0';
		map = gnl_strjoin(map, buf);
		if (!map)
			ft_exit("Allocating memory failed");
	}
	close(fd);
	return (map);
}

void	check_args(char *argv)
{
	int		fd;
	char	*map;

	check_extension(argv, ".ber");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("Opening file failed");
	map = ft_read(fd);
	if (!map)
		ft_exit("Empty map");
	
}
