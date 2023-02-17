/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:37:06 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/13 11:23:47 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

# define H 90
# define W 90

# define TOP 126
# define BOTTOM 125
# define RIGHT 124
# define LEFT 123

# define W_TOP 13
# define S_BOTTOM 1
# define D_RIGHT 2
# define A_LEFT 0

# define ESC 53

# define MAP 1
# define MAP_D 2
# define ARGS 3

typedef struct s_len
{
	int	x;
	int	y;
}	t_len;

typedef struct s_dimension
{
	int	height;
	int	width;
}	t_dimension;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_ele
{
	int	exit;
	int	collectible;
	int	player;
	int	enemies;
}	t_ele;

typedef struct s_data
{
	t_dimension	dims;
	void		*mlx;
	void		*win;
	t_position	player_pos;
	t_position	exit_pos;
	t_position	enemies_pos;
	void		*space;
	void		*wall;
	void		*exit;
	void		*items;
	void		*player;
	void		*enemies;
	char		*holder;
	char		**map_data;
	char		**map_copy;
	int			img_w;
	int			img_h;
	int			score;
	int			curr_score;
	int			moves;
}	t_data;

void		get_started(t_data *so_long);
int			get_map_and_dims(t_data *so_long, char *path);
int			map_checker(t_data *so_long);
int			argument_checker(t_data *so_long, char *av);
void		map_forming(t_data *so_long, int is_first);
void		start_playing(t_data *so_long);
void		move_player(t_data *so_long, int where);
void		free_double(char **tab);
int			ft_exit(t_data *so_long);
void		ft_error(t_data *so_long, int where);
void		check_images(t_data *so_long);

//bonus
void		get_started_bonus(t_data *so_long);
void		start_playing_bonus(t_data *so_long);
int			map_checker_bonus(t_data *so_long);
int			check_ele(char **map);
int			check_rectangular(char **map);
int			check_surrounded(char **map);
void		init_ele(t_ele *element);
int			check_limits(char **map);
void		map_forming_bonus(t_data *so_long, int is_first);
void		put_image(t_data *so_long, void	*image, int x, int y);
void		put_exit(t_data *so_long, int x, int y);
void		put_player(t_data *so_long, void *image, int x, int y);
void		put_enemies(t_data *so_long, int x, int y);
void		move_player_bonus(t_data *so_long, int where);
int			move_enemies_and_animate_exit(t_data *so_long);
void		door_animation(t_data *so_long);
int			ft_exit_bonus(t_data *so_long);
void		check_images_bonus(t_data *so_long);

#endif 