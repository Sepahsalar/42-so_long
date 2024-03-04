/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/04 18:52:36 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_extension(char *map, char *extension)
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
		ft_exit("Initializing failed");
	while (i != 0)
	{
		i = read(fd, buf, 50);
		if (i == -1)
			ft_exit("Reading file failed");
		buf[i] = '\0';
		map = gnl_strjoin(map, buf);
		if (!map)
			ft_exit("Joining failed");
	}
	close(fd);
	return (map);
}

static t_line	*check_rectangular(char **total_lines, t_line *line)
{
	int		i;

	i = 0;
	while (total_lines[i + 1])
	{
		line->width = ft_strlen(total_lines[i++]);
		if (line->width != ft_strlen(total_lines[i]))
			ft_exit("Invalid map: Not rectangular");
	}
	line->width = ft_strlen(total_lines[i]);
	line->count = i;
	return (line);
}

void	check_letters(char *map)
{
	
}

void	check_args(char *argv, t_line *line)
{
	int		fd;
	char	*map;
	char	**total_lines;
	int		line_count;

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
	line = check_rectangular(total_lines, line);
	check_letters(map);
}
