/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_playing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:06:02 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/07 12:46:34 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_events(int keycode, t_data *so_long)
{
	if (keycode == W_TOP || keycode == TOP)
		move_player_bonus(so_long, TOP);
	else if (keycode == S_BOTTOM || keycode == BOTTOM)
		move_player_bonus(so_long, BOTTOM);
	else if (keycode == D_RIGHT || keycode == RIGHT)
	{
		mlx_destroy_image(so_long->mlx, so_long->player);
		so_long->player = mlx_xpm_file_to_image(so_long->mlx, \
			"TEXTURES/p_r.xpm", &so_long->img_w, &so_long->img_h);
		check_images_bonus(so_long);
		move_player_bonus(so_long, RIGHT);
	}
	else if (keycode == A_LEFT || keycode == LEFT)
	{
		mlx_destroy_image(so_long->mlx, so_long->player);
		so_long->player = mlx_xpm_file_to_image(so_long->mlx, \
			"TEXTURES/p_l.xpm", &so_long->img_w, &so_long->img_h);
		check_images_bonus(so_long);
		move_player_bonus(so_long, LEFT);
	}
	map_forming_bonus(so_long, 0);
}

int	keypress(int keycode, t_data *so_long)
{
	if (keycode == ESC)
		ft_exit_bonus(so_long);
	game_events(keycode, so_long);
	return (0);
}

void	start_playing_bonus(t_data *so_long)
{
	mlx_hook(so_long->win, 2, 0, keypress, so_long);
	mlx_hook(so_long->win, 17, 0, ft_exit_bonus, so_long);
	mlx_loop_hook(so_long->mlx, &move_enemies_and_animate_exit, so_long);
}
