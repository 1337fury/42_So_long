/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_started_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:41:55 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/04 11:20:57 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_started_bonus(t_data *so_long)
{
	so_long->mlx = mlx_init();
	so_long->win = mlx_new_window(so_long->mlx, (so_long->dims.width * W), \
				(so_long->dims.height * H), "so_long");
	so_long->img_w = W;
	so_long->img_h = H;
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "TEXTURES/wall.xpm", \
		&so_long->img_w, &so_long->img_h);
	so_long->space = mlx_xpm_file_to_image(so_long->mlx, "TEXTURES/space.xpm", \
		&so_long->img_w, &so_long->img_h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "TEXTURES/door-1.xpm", \
		&so_long->img_w, &so_long->img_h);
	so_long->items = mlx_xpm_file_to_image(so_long->mlx, "TEXTURES/collec.xpm", \
	&so_long->img_w, &so_long->img_h);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "TEXTURES/p_r.xpm", \
		&so_long->img_w, &so_long->img_h);
	so_long->enemies = mlx_xpm_file_to_image(so_long->mlx, "TEXTURES/e_l.xpm", \
		&so_long->img_w, &so_long->img_h);
}
