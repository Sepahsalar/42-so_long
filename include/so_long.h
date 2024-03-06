/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:48:15 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/06 13:56:26 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_line
{
	size_t	width;
	int		count;
}			t_line;

int		check_args(char *argv, t_line *line);
void	ft_exit(char *message);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_read(int fd);
void	check_extension(char *map, char *extension);
void	check_pe(char *map);
int		check_letters(char *map);

#endif
