/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_forming.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:51 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/05 08:35:06 by abdeel-o         ###   ########.fr       */
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
}

void	not_first_forming(t_data *so_long, int is_first)
{
	if (!is_first)
		if (!(so_long->player_pos.x == so_long->exit_pos.x \
			&& so_long->exit_pos.y == so_long->player_pos.y))
			so_long->map_data[so_long->exit_pos.y][so_long->exit_pos.x] = 'E';
}

void	map_forming(t_data *so_long, int is_first)
{
	t_position	pos;

	pos.y = -1;
	not_first_forming(so_long, is_first);
	while (so_long->map_data[++pos.y])
	{
		pos.x = -1;
		while (so_long->map_data[pos.y][++pos.x] != '\0')
		{
			if (so_long->map_data[pos.y][pos.x] == '1')
				put_image(so_long, so_long->wall, pos.x, pos.y);
			else if (so_long->map_data[pos.y][pos.x] == 'C')
			{
				if (is_first)
					so_long->score++;
				put_image(so_long, so_long->items, pos.x, pos.y);
			}
			else if (so_long->map_data[pos.y][pos.x] == '0')
				put_image(so_long, so_long->space, pos.x, pos.y);
			else if (so_long->map_data[pos.y][pos.x] == 'E')
				put_exit(so_long, pos.x, pos.y);
			else if (so_long->map_data[pos.y][pos.x] == 'P')
				put_player(so_long, so_long->player, pos.x, pos.y);
		}
	}
}
