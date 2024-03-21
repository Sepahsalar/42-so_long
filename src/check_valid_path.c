/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:47:18 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/21 13:19:00 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	find_character(char **total_lines, t_map *map, char c)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < (map->line_count - 1))
	{
		j = 0;
		while (j < (map->line_width - 1))
		{
			if (total_lines[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_loc	find_location(char **total_lines, t_map *map, char c)
{
	int		i;
	size_t	j;
	t_loc	loc;

	i = 0;
	j = 0;
	while (i < (map->line_count - 1))
	{
		j = 0;
		while (j < (map->line_width - 1))
		{
			if (total_lines[i][j] == c)
			{
				loc.x = j;
				loc.y = i;
			}
			j++;
		}
		i++;
	}
	return (loc);
}

static void	fill_map(char **total_lines, t_loc size, t_loc cur, char check)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| total_lines[cur.y][cur.x] == check
		|| total_lines[cur.y][cur.x] == 'F')
		return ;
	total_lines[cur.y][cur.x] = 'F';
	fill_map(total_lines, size, (t_loc){cur.x + 1, cur.y, cur.c}, check);
	fill_map(total_lines, size, (t_loc){cur.x - 1, cur.y, cur.c}, check);
	fill_map(total_lines, size, (t_loc){cur.x, cur.y + 1, cur.c}, check);
	fill_map(total_lines, size, (t_loc){cur.x, cur.y - 1, cur.c}, check);
}

// void	print_map(char **a, t_map *map)
// {
// 	int		i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < map->line_count)
// 	{
// 		j = 0;
// 		while (j < map->line_width)
// 		{
// 			ft_printf("%c ", a[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n");
// }

void	check_valid_path(char **total_lines, t_map *map)
{
	t_loc	p_loc;
	int		e_loc;
	int		c_loc;
	t_loc	size;

	size.x = map->line_width;
	size.y = map->line_count;
	p_loc = find_location(total_lines, map, 'P');
	// print_map(total_lines, map);
	fill_map(total_lines, size, p_loc, '1');
	e_loc = find_character(total_lines, map, 'E');
	c_loc = find_character(total_lines, map, 'C');
	if (e_loc || c_loc)
		ft_exit("Invalid map: No valid path");
}
