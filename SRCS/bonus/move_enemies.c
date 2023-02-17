/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:20:24 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/07 12:35:20 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	move_up(t_data *so_long, t_position *pos)
{
	if (so_long->map_data[pos->y - 1][pos->x] != '1' && \
		so_long->map_data[pos->y - 1][pos->x] != 'C' && \
		so_long->map_data[pos->y - 1][pos->x] != 'E')
	{
		so_long->enemies_pos.y -= 1;
		if (so_long->map_data[pos->y][pos->x] == 'P')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = '2';
		so_long->map_data[pos->y + 1][pos->x] = '0';
	}
}

void	move_down(t_data *so_long, t_position *pos)
{
	if (so_long->map_data[pos->y + 1][pos->x] != '1' && \
		so_long->map_data[pos->y + 1][pos->x] != 'C' && \
		so_long->map_data[pos->y - 1][pos->x] != 'E')
	{
		so_long->enemies_pos.y += 1;
		if (so_long->map_data[pos->y][pos->x] == 'P')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = '2';
		so_long->map_data[pos->y - 1][pos->x] = '0';
	}
}

void	move_right(t_data *so_long, t_position *pos)
{
	mlx_destroy_image(so_long->mlx, so_long->enemies);
	so_long->enemies = mlx_xpm_file_to_image(so_long->mlx, \
		"TEXTURES/e_r.xpm", &so_long->img_w, &so_long->img_h);
	check_images_bonus(so_long);
	if (so_long->map_data[pos->y][pos->x + 1] != '1' && \
		so_long->map_data[pos->y][pos->x + 1] != 'C' && \
		so_long->map_data[pos->y - 1][pos->x] != 'E')
	{
		so_long->enemies_pos.x += 1;
		if (so_long->map_data[pos->y][pos->x] == 'P')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = '2';
		so_long->map_data[pos->y][pos->x - 1] = '0';
	}
}

void	move_left(t_data *so_long, t_position *pos)
{
	mlx_destroy_image(so_long->mlx, so_long->enemies);
	so_long->enemies = mlx_xpm_file_to_image(so_long->mlx, \
		"TEXTURES/e_l.xpm", &so_long->img_w, &so_long->img_h);
	check_images_bonus(so_long);
	if (so_long->map_data[pos->y][pos->x - 1] != '1' && \
		so_long->map_data[pos->y][pos->x - 1] != 'C' && \
		so_long->map_data[pos->y - 1][pos->x] != 'E')
	{
		so_long->enemies_pos.x -= 1;
		if (so_long->map_data[pos->y][pos->x] == 'P')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = '2';
		so_long->map_data[pos->y][pos->x + 1] = '0';
	}
}

int	move_enemies_and_animate_exit(t_data *so_long)
{
	static int	num;
	int			random;
	char		*dir;

	dir = "udrl";
	if (num == 2000)
	{
		random = rand() % 4;
		if (dir[random] == 'u')
			move_up(so_long, &so_long->enemies_pos);
		else if (dir[random] == 'd')
			move_down(so_long, &so_long->enemies_pos);
		else if (dir[random] == 'r')
			move_right(so_long, &so_long->enemies_pos);
		else if (dir[random] == 'l')
			move_left(so_long, &so_long->enemies_pos);
		map_forming_bonus(so_long, 0);
		num = 0;
	}
	door_animation(so_long);
	num++;
	return (0);
}
