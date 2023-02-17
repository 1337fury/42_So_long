/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_forming_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:51 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/10 16:09:07 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	not_first_forming(t_data *so_long, int is_first)
{
	if (!is_first)
		if (!(so_long->player_pos.x == so_long->exit_pos.x \
			&& so_long->exit_pos.y == so_long->player_pos.y))
			so_long->map_data[so_long->exit_pos.y][so_long->exit_pos.x] = 'E';
}

void	put_elements(char c, t_data *so_long, int x, int y)
{
	if (c == '1')
		put_image(so_long, so_long->wall, x, y);
	else if (c == '0')
		put_image(so_long, so_long->space, x, y);
	else if (c == 'C')
		put_image(so_long, so_long->items, x, y);
	else if (c == 'E')
		put_exit(so_long, x, y);
	else if (c == '2')
	{
		put_image(so_long, so_long->space, x, y);
		put_enemies(so_long, x, y);
	}
	else if (c == 'P')
		put_player(so_long, so_long->player, x, y);
}

void	map_forming_bonus(t_data *so_long, int is_first)
{
	t_position	pos;
	char		*moves;
	char		*temp;

	pos.y = -1;
	not_first_forming(so_long, is_first);
	while (so_long->map_data[++pos.y])
	{
		pos.x = -1;
		while (so_long->map_data[pos.y][++pos.x] != '\0')
		{
			if (so_long->map_data[pos.y][pos.x] == 'C')
			{
				if (is_first)
					so_long->score++;
			}
			put_elements(so_long->map_data[pos.y][pos.x] \
				, so_long, pos.x, pos.y);
		}
	}
	temp = ft_itoa(so_long->moves);
	moves = ft_strjoin("moves : ", temp);
	mlx_string_put(so_long->mlx, so_long->win, 10, 5, 0xFFFFFF, moves);
	free(moves);
	free(temp);
}
