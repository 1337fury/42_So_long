/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:35:32 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:34 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *so_long)
{
	so_long->dims.height = 0;
	so_long->dims.width = 0;
	so_long->mlx = NULL;
	so_long->win = NULL;
	so_long->player_pos.x = 0;
	so_long->player_pos.y = 0;
	so_long->exit_pos.x = 0;
	so_long->exit_pos.y = 0;
	so_long->enemies_pos.x = 0;
	so_long->enemies_pos.y = 0;
	so_long->space = NULL;
	so_long->wall = NULL;
	so_long->exit = NULL;
	so_long->items = NULL;
	so_long->player = NULL;
	so_long->enemies = NULL;
	so_long->holder = NULL;
	so_long->map_data = NULL;
	so_long->map_copy = NULL;
	so_long->img_w = 0;
	so_long->img_h = 0;
	so_long->score = 0;
	so_long->curr_score = 0;
	so_long->moves = 0;
}

int	main(int ac, char **av)
{
	t_data	*so_long;
	int		map_status;

	if (ac == 2)
	{
		so_long = (t_data *)malloc(sizeof(t_data));
		if (!so_long)
			return (1);
		init(so_long);
		map_status = get_map_and_dims(so_long, av[1]);
		if (!map_status)
		{
			free(so_long);
			return (1);
		}
		if (argument_checker(so_long, av[1]) && map_checker_bonus(so_long))
		{
			get_started_bonus(so_long);
			check_images_bonus(so_long);
			map_forming_bonus(so_long, 1);
			start_playing_bonus(so_long);
			mlx_loop(so_long->mlx);
		}
	}
	return (0);
}
