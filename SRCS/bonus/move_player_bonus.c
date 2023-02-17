/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:43:52 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/04 11:38:57 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_top_bonus(t_data *so_long, t_position *pos)
{
	if (so_long->map_data[pos->y - 1][pos->x] != '1')
	{
		so_long->player_pos.y -= 1;
		if (so_long->map_data[pos->y][pos->x] == 'C')
			so_long->curr_score++;
		else if (so_long->map_data[pos->y][pos->x] == '2')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		else if (so_long->map_data[pos->y][pos->x] == 'E' \
			&& (so_long->score == so_long->curr_score))
		{
			ft_printf("YOU WIN !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = 'P';
		so_long->map_data[pos->y + 1][pos->x] = '0';
		so_long->moves++;
	}
}

void	move_to_bottom_bonus(t_data *so_long, t_position *pos)
{
	if (so_long->map_data[pos->y + 1][pos->x] != '1')
	{
		so_long->player_pos.y += 1;
		if (so_long->map_data[pos->y][pos->x] == 'C')
			so_long->curr_score++;
		else if (so_long->map_data[pos->y][pos->x] == '2')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		else if (so_long->map_data[pos->y][pos->x] == 'E' \
			&& (so_long->score == so_long->curr_score))
		{
			ft_printf("YOU WIN !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = 'P';
		so_long->map_data[pos->y - 1][pos->x] = '0';
		so_long->moves++;
	}
}

void	move_to_right_bonus(t_data *so_long, t_position *pos)
{
	if (so_long->map_data[pos->y][pos->x + 1] != '1')
	{
		so_long->player_pos.x += 1;
		if (so_long->map_data[pos->y][pos->x] == 'C')
			so_long->curr_score++;
		else if (so_long->map_data[pos->y][pos->x] == '2')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		else if (so_long->map_data[pos->y][pos->x] == 'E' \
			&& (so_long->score == so_long->curr_score))
		{
			ft_printf("YOU WIN !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = 'P';
		so_long->map_data[pos->y][pos->x - 1] = '0';
		so_long->moves++;
	}
}

void	move_to_left_bonus(t_data *so_long, t_position *pos)
{
	if (so_long->map_data[pos->y][pos->x - 1] != '1')
	{
		so_long->player_pos.x -= 1;
		if (so_long->map_data[pos->y][pos->x] == 'C')
			so_long->curr_score++;
		else if (so_long->map_data[pos->y][pos->x] == '2')
		{
			ft_printf("YOU LOSE !");
			ft_exit_bonus(so_long);
		}
		else if (so_long->map_data[pos->y][pos->x] == 'E' \
			&& (so_long->score == so_long->curr_score))
		{
			ft_printf("YOU WIN !");
			ft_exit_bonus(so_long);
		}
		so_long->map_data[pos->y][pos->x] = 'P';
		so_long->map_data[pos->y][pos->x + 1] = '0';
		so_long->moves++;
	}
}

void	move_player_bonus(t_data *so_long, int where)
{
	if (where == TOP)
		move_to_top_bonus(so_long, &so_long->player_pos);
	else if (where == BOTTOM)
		move_to_bottom_bonus(so_long, &so_long->player_pos);
	else if (where == RIGHT)
		move_to_right_bonus(so_long, &so_long->player_pos);
	else if (where == LEFT)
		move_to_left_bonus(so_long, &so_long->player_pos);
}
