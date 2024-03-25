/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:36:40 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/25 17:37:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*gnl_resultjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		ft_exit("Allocating memory for joining failed");
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			ft_exit("Allocating memory for the first arg of strjoin failed");
		s1[0] = '\0';
	}
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	result = gnl_resultjoin(s1, s2);
	if (!result)
		ft_exit("Allocating memory for joining failed");
	free(s1);
	return (result);
}

void	check_extension(char *str, char *extension)
{
	size_t	map_len;

	map_len = ft_strlen(str);
	if (map_len <= 4)
		ft_exit("Wrong file extension\nEx: map.ber");
	str = str + map_len - 4;
	if (ft_strncmp(str, extension, 4))
		ft_exit("Wrong file extension\nEx: map.ber");
}

void	check_letters(char *str)
{
	int		i;
	char	*check;

	i = 0;
	check = ft_strchr(str, 'P');
	if (check)
		if (ft_strchr(check + 1, 'P'))
			ft_exit("Invalid map: More than 1 starting position");
	check = ft_strchr(str, 'E');
	if (check)
		if (ft_strchr(check + 1, 'E'))
			ft_exit("Invalid map: More than 1 map exit");
	if (!(ft_strchr(str, 'C')) || !(ft_strchr(str, 'P'))
		|| !(ft_strchr(str, 'E')) || !(ft_strchr(str, '1')))
		ft_exit("Invalid map: Not enough characters");
	while (str[i])
	{
		if (!(ft_strchr("01CEP\n", str[i])))
			ft_exit("Invalid map: Wrong characters");
		i++;
	}
}

void	check_walls(char **total_lines, t_map *map)
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
