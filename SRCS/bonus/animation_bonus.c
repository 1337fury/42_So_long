/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:54:27 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/07 12:42:27 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_animation(t_data *so_long)
{
	static int	i;

	if (i == 0 || i == 1000 || i == 2000 || i == 3000)
		mlx_destroy_image(so_long->mlx, so_long->exit);
	if (i == 0)
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"TEXTURES/door-2.xpm", &so_long->img_w, &so_long->img_h);
	else if (i == 1000)
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"TEXTURES/door-3.xpm", &so_long->img_w, &so_long->img_h);
	else if (i == 2000)
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"TEXTURES/door-4.xpm", &so_long->img_w, &so_long->img_h);
	if (i == 0 || i == 1000 || i == 2000)
		check_images_bonus(so_long);
	else if (i == 3000)
	{
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"TEXTURES/door-1.xpm", &so_long->img_w, &so_long->img_h);
		check_images_bonus(so_long);
		i = 0;
	}
	i++;
}
