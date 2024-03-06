/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:36:40 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/06 13:56:00 by asohrabi         ###   ########.fr       */
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
		return (NULL);
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
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (ft_free(s1));
	result = ft_resultjoin(s1, s2);
	if (!result)
		return (ft_free(s1));
	free(s1);
	return (result);
}

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

void	check_pe(char *map)
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

int	check_letters(char *map)
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
