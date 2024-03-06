/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/06 18:02:59 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_line	*check_rectangular(char **total_lines)
{
	int		i;
	t_line	*line;

	i = 0;
	line = malloc(sizeof(t_line));
	while (total_lines[i + 1])
	{
		line->width = ft_strlen(total_lines[i]);
		if (line->width != ft_strlen(total_lines[i + 1]))
			ft_exit("Invalid map: Not rectangular");
		i++;
	}
	line->width = ft_strlen(total_lines[i]);
	line->count = i + 1;
	if (line->count <= 0 || line->width <= 0)
		ft_exit("Invalid map");
	return (line);
}

static void	check_walls(char **total_lines, t_line *line)
{
	size_t	i;

	i = 0;
	while (i < line->width)
	{
		if (total_lines[0][i] != '1' || total_lines[line->count - 1][i] != '1')
			ft_exit("Invalid map: Not surrounded with walls");
		i++;
	}
	i = 0;
	while (total_lines[i])
	{
		if (total_lines[i][0] != '1' || total_lines[i][line->width - 1] != '1')
			ft_exit("Invalid map: Not surrounded with walls");
		i++;
	}
}
//remember to free memory
int	check_args(char *argv)
{
	int		fd;
	char	*map;
	char	**total_lines;
	int		collectible_count;
	t_line	*line;

	check_extension(argv, ".ber");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("Opening file failed");
	map = ft_read(fd);
	if (!map)
		ft_exit("Empty map");
	total_lines = ft_split(map, '\n');
	if (!total_lines)
		ft_exit("Invalid map");
	line = check_rectangular(total_lines);
	if (!line)
		ft_exit("Allocating memory failed");
	collectible_count = check_letters(map);
	check_walls(total_lines, line);
	check_valid_path(total_lines, line);
	close(fd);
	return (collectible_count);
}
