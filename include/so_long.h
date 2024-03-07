/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:48:15 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/07 16:18:48 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	size_t	line_width;
	int		line_count;
	int		c_count;
}			t_map;

typedef struct s_loc
{
	size_t	x;
	int		y;
}			t_loc;

t_map	*check_args(char *argv);
void	ft_exit(char *message);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_read(int fd);
void	check_extension(char *str, char *extension);
void	check_pe(char *str);
int		check_letters(char *str);
void	check_valid_path(char **total_lines, t_map *map);
void	ft_free(char **array);

#endif
