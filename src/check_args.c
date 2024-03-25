/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/25 17:36:15 by asohrabi         ###   ########.fr       */
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

static t_map	*check_rec_helper(int fd, t_map *map, int count)
{
	char	*current_line;
	char	*next_line;

	map->line_count = count + 1;
	current_line = get_next_line(fd);
	next_line = get_next_line(fd);
	while (count > 0)
	{
		if (ft_strlen_con(current_line) != ft_strlen_con(next_line))
		{
			close(fd);
			free(map);
			free(current_line);
			free(next_line);
			ft_exit("Invalid map: Not rectangular");
		}
		free(next_line);
		next_line = get_next_line(fd);
		count--;
	}
	close(fd);
	map->line_width = ft_strlen_con(current_line);
	free(current_line);
	free(next_line);
	return (map);
}

static int	count_lines(char *str)
{
	int	count;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
}

static t_map	*check_rectangular(char *str, char *argv)
{
	int		count;
	int		fd;
	t_map	*map;

	count = count_lines(str);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		ft_exit("Opening file failed");
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		free(str);
		close(fd);
		ft_exit("Allocating memory for map failed");
	}
	map = check_rec_helper(fd, map, count);
	if (map->line_count <= 0 || map->line_width <= 0)
	{
		free(str);
		free(map);
		ft_exit("Invalid map");
	}
	return (map);
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
	{
		free(str);
		ft_exit("Invalid map");
	}
	map = check_rectangular(str, argv);
	if (!map)
	{
		free(str);
		ft_exit("Creating map failed");
	}
	check_letters(str);
	free(str);
	close(fd);
	check_walls(total_lines, map);
	check_valid_path(total_lines, map);
	ft_free(total_lines);
	return (map);
}
