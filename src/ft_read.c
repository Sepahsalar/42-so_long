/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:48:14 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/22 12:54:24 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_read(int fd)
{
	char	buf[51];
	int		i;
	char	*str;

	i = 1;
	str = ft_calloc(1, 1);
	if (!str)
		ft_exit("Initializing string in read function failed");
	while (i != 0)
	{
		i = read(fd, buf, 50);
		if (i == -1)
			ft_exit("Reading file failed");
		buf[i] = '\0';
		str = gnl_strjoin(str, buf);
		if (!str)
			ft_exit("Joining failed");
	}
	close(fd);
	return (str);
}
