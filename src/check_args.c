/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:56 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/06 11:54:44 by asohrabi         ###   ########.fr       */
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

static void	check_pe(char *map)
{
	char	*check;

	check = ft_strchr(map, 'P');
	if (check)
		if (ft_strchr(check + 1, 'P'))
			ft_exit("Invalid map: More than 1 starting position");
	check = ft_strchr(map, 'E');
	if (check)
		if (ft_strchr(check + 1, 'E'))
			ft_exit("Invalid map: More than 1 map exit");
}

static int	check_letters(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!(ft_strchr(map, 'C')) || !(ft_strchr(map, 'P'))
		|| !(ft_strchr(map, 'E')) || !(ft_strchr(map, '1')))
		ft_exit("Invalid map: Not enough characters");
	check_pe(map);
	while (map[i])
	{
		if (!(ft_strchr("01CEP\n", map[i])))
			ft_exit("Invalid map: Not enough characters");
		if (map[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

static void	check_walls()
{
	
}

void	check_args(char *argv, t_line *line)
{
	int		fd;
	char	*map;
	char	**total_lines;
	int		line_count;
	int		collectible_count;

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
	collectible_count = check_letters(map);
	check_walls(total_lines, line);
}
