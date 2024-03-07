/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/07 15:40:58 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_map	*check_rectangular(char **total_lines)
{
	int		i;
	t_map	*map;

	i = 0;
	map = malloc(sizeof(t_map));
	while (total_lines[i + 1])
	{
		map->line_width = ft_strlen(total_lines[i]);
		if (map->line_width != ft_strlen(total_lines[i + 1]))
			ft_exit("Invalid map: Not rectangular");
		i++;
	}
	map->line_width = ft_strlen(total_lines[i]);
	map->line_count = i + 1;
	if (map->line_count <= 0 || map->line_width <= 0)
		ft_exit("Invalid map");
	return (map);
}

static void	check_walls(char **total_lines, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->line_width)
	{
		if (total_lines[0][i] != '1'
			|| total_lines[map->line_count - 1][i] != '1')
			ft_exit("Invalid map: Not surrounded with walls");
		i++;
	}
	i = 0;
	while (total_lines[i])
	{
		if (total_lines[i][0] != '1'
			|| total_lines[i][map->line_width - 1] != '1')
			ft_exit("Invalid map: Not surrounded with walls");
		i++;
	}
}

t_map	*check_args(char *argv)
{
	int		fd;
	char	*str;
	char	**total_lines;
	t_map	*map;

	check_extension(argv, ".ber");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("Opening file failed");
	str = ft_read(fd);
	if (!str)
		ft_exit("Empty map");
	total_lines = ft_split(str, '\n');
	if (!total_lines)
		ft_exit("Invalid map");
	map = check_rectangular(total_lines);
	if (!map)
		ft_exit("Allocating memory failed");
	map->c_count = check_letters(str);
	check_walls(total_lines, map);
	check_valid_path(total_lines, map);
	ft_free(total_lines);
	close(fd);
	return (map);
}
