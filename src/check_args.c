/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/21 15:32:15 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static size_t	ft_strlen_con(char *line)
{
	size_t	width;

	width = 0;
	if (ft_strchr(line, '\n'))
		width = ft_strlen(line) - 1;
	else
		width = ft_strlen(line);
	return (width);
}

static t_map	*check_rectangular(char *argv)
{
	int		count;
	int		fd;
	t_map	*map;
	char	*current_line;
	char	*next_line;
// It would be better to add a function to count lines and
// change the condition of while connected to the number of lines
	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("Opening file failed");
	map = malloc(sizeof(t_map));
	current_line = get_next_line(fd);
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		if (ft_strlen_con(current_line) != ft_strlen_con(next_line))
		{
			close(fd);
			ft_exit("Invalid map: Not rectangular");
		}
		count++;
		next_line = get_next_line(fd);
		// ft_printf("line: %s\n", next_line);
	}
	close(fd);
	map->line_width = ft_strlen_con(current_line);
	map->line_count = count + 1;
	if (map->line_count <= 0 || map->line_width <= 0)
		ft_exit("Invalid map");
	free(current_line);
	free(next_line);
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

// char	*read_file()
// {
// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 		ft_exit("Opening file failed");
// 	str = ft_read(fd);
// 	if (!str)
// 		ft_exit("Empty map");
// }

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
	map = check_rectangular(argv);
	if (!map)
		ft_exit("Allocating memory failed");
	check_letters(str);
	check_walls(total_lines, map);
	check_valid_path(total_lines, map);
	ft_free(total_lines);
	free(str);
	close(fd);
	return (map);
}
