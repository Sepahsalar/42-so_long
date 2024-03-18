/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:48:15 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/18 20:03:31 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_loc
{
	size_t	x;
	int		y;
	char	c;
}			t_loc;

typedef struct s_collect_loc
{
	size_t					x;
	int						y;
	int						enabled;
	struct s_collect_loc	*next;
}							t_collect_loc;

typedef struct s_elem
{
	mlx_image_t			*empty;
	mlx_image_t			*wall;
	mlx_image_t			*collect;
	mlx_image_t			*exit;
	mlx_image_t			*player;
	t_loc				player_loc;
	t_collect_loc		*collect_loc;
}						t_elem;

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

typedef struct s_all_var
{
	mlx_t	*window;
	t_elem	*elems;
	t_map	*map;
	int		*move_count;
}			t_all_var;

t_all_var		check_args(char *argv); //check if the return should be pointer
void			ft_exit(char *message);
char			*gnl_strjoin(char *s1, char *s2);
char			*ft_read(int fd);
void			check_extension(char *str, char *extension);
void			check_pe(char *str);
void			check_letters(char *str);
t_loc			check_valid_path(char **total_lines, t_map *map);
void			ft_free(char **array);
void			cal_size(t_map *map);
t_elem			*create_elements(mlx_t *window, t_map *map, char *argv);
void			create_instance(mlx_t *window, t_elem *elements,
					t_map *map, char *arg);
void			press_key(mlx_key_data_t keydata, void *param);
void			check_collectible(t_all_var	*all);
t_collect_loc	*collectible_list(char *argv, t_collect_loc *first);

#endif
