/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:47:18 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/06 18:30:29 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h> //delete this

static t_loc	find_location(char **total_lines, t_line *line, char c)
{
	int		i;
	size_t	j;
	t_loc	p_location;

	i = 1;
	j = 1;
	while (i < line->count)
	{
		j = 1;
		while (j < line->width)
		{
			if (total_lines[i][j] == c)
			{
				p_location.x = j;
				p_location.y = i;
			}
			j++;
		}
		i++;
	}
	return (p_location);
}

static void	fill_map(char **total_lines, t_loc size, t_loc cur, char check)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| total_lines[cur.y][cur.x] == check
		|| total_lines[cur.y][cur.x] == 'F')
		return ;
	total_lines[cur.y][cur.x] = 'F';
	fill_map(total_lines, size, (t_loc){cur.x + 1, cur.y}, check);
	fill_map(total_lines, size, (t_loc){cur.x - 1, cur.y}, check);
	fill_map(total_lines, size, (t_loc){cur.x, cur.y + 1}, check);
	fill_map(total_lines, size, (t_loc){cur.x, cur.y - 1}, check);
}

void	print_map(char **a, t_line *line)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < line->count)
	{
		j = 0;
		while (j < line->width)
		{
			printf("%c ", a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

//use flood fill, change every 0, c, e to t and then 
//at the end i should check are there any c or e remained or not
void	check_valid_path(char **total_lines, t_line *line)
{
	t_loc	p_loc;
	t_loc	e_loc;
	t_loc	c_loc;
	t_loc	size;

	size.x = line->width;
	size.y = line->count;
	p_loc = find_location(total_lines, line, 'P');
	// print_map(total_lines, line);
	fill_map(total_lines, size, p_loc, '1');
	// print_map(total_lines, line);
	e_loc = find_location(total_lines, line, 'E');
	c_loc = find_location(total_lines, line, 'C');
	if (e_loc.y || c_loc.y)
		ft_exit("Invalid map: No valid path");
}
