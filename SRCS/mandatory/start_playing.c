/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_playing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:06:02 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/07 12:10:10 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_events(int keycode, t_data *so_long)
{
	if (keycode == W_TOP || keycode == TOP)
		move_player(so_long, TOP);
	else if (keycode == S_BOTTOM || keycode == BOTTOM)
		move_player(so_long, BOTTOM);
	else if (keycode == D_RIGHT || keycode == RIGHT)
	{
		mlx_destroy_image(so_long->mlx, so_long->player);
		so_long->player = mlx_xpm_file_to_image(so_long->mlx, \
			"TEXTURES/p_r.xpm", &so_long->img_w, &so_long->img_h);
		check_images(so_long);
		move_player(so_long, RIGHT);
	}
	else if (keycode == A_LEFT || keycode == LEFT)
	{
		mlx_destroy_image(so_long->mlx, so_long->player);
		so_long->player = mlx_xpm_file_to_image(so_long->mlx, \
			"TEXTURES/p_l.xpm", &so_long->img_w, &so_long->img_h);
		check_images(so_long);
		move_player(so_long, LEFT);
	}
	map_forming(so_long, 0);
}

int	keypress(int keycode, t_data *so_long)
{
	int	p_position_x;
	int	p_position_y;

	p_position_x = so_long->player_pos.x;
	p_position_y = so_long->player_pos.y;
	if (keycode == ESC)
		ft_exit(so_long);
	game_events(keycode, so_long);
	if (!(so_long->player_pos.x == p_position_x \
		&& so_long->player_pos.y == p_position_y))
		ft_printf("Moves: %d\n", so_long->moves);
	return (0);
}

void	start_playing(t_data *so_long)
{
	mlx_hook(so_long->win, 2, 0, keypress, so_long);
	mlx_hook(so_long->win, 17, 0, ft_exit, so_long);
}
