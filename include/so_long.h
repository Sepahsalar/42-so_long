/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:48:15 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/14 17:50:43 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_elem
{
	mlx_image_t	*empty;
	mlx_image_t	*wall;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}				t_elem;

typedef struct s_map
{
	size_t	line_width;
	int		line_count;
	int		c_count;
	int		image_width;
	int		image_height;
	int		window_width;
	int		window_height;
}			t_map;

typedef struct s_loc
{
	size_t	x;
	int		y;
	char	c;
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
void	cal_size(t_map *map);
t_elem	*create_elements(mlx_t *window, t_map *map);
void	create_instance(mlx_t *window, t_elem *elements, t_map *map, char *arg);

#endif
