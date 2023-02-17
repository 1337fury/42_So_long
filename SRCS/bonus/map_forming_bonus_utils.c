/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_formin_bonus_utls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:41:41 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/04 21:41:57 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *so_long, void	*image, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win, image, x * W, y * H);
}

void	put_exit(t_data *so_long, int x, int y)
{
	so_long->exit_pos.x = x;
	so_long->exit_pos.y = y;
	put_image(so_long, so_long->exit, x, y);
}

void	put_player(t_data *so_long, void *image, int x, int y)
{
	so_long->player_pos.x = x;
	so_long->player_pos.y = y;
	if ((so_long->player_pos.x == so_long->exit_pos.x) \
		&& (so_long->player_pos.y == so_long->exit_pos.y))
		put_exit(so_long, x, y);
	else
		put_image(so_long, so_long->space, x, y);
	put_image(so_long, image, x, y);
	put_image(so_long, image, x, y);
}

void	put_enemies(t_data *so_long, int x, int y)
{
	so_long->enemies_pos.x = x;
	so_long->enemies_pos.y = y;
	put_image(so_long, so_long->enemies, x, y);
}
