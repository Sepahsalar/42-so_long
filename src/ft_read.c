/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:48:14 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/06 13:48:38 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_read(int fd)
{
	char	buf[51];
	int		i;
	char	*map;

	i = 1;
	map = ft_calloc(1, 1);
	if (!map)
		ft_exit("Allocating memory failed");
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