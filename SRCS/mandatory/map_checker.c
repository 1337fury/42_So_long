/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:36:12 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/06 09:00:43 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(char **map, t_position *player_pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_pos->x = j;
				player_pos->y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int i, int j, t_len *len)
{
	if (i < 0 || i >= len->y || j < 0 || j >= len->x || map[i][j] == '1')
		return ;
	else
	{
		map[i][j] = '1';
		flood_fill(map, i + 1, j, len);
		flood_fill(map, i - 1, j, len);
		flood_fill(map, i, j + 1, len);
		flood_fill(map, i, j - 1, len);
	}
}

int	is_valid(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_path(char **copy)
{
	t_position	player_pos;
	t_len		len;

	if (!copy)
		return (0);
	len.y = 0;
	len.x = ft_strlen_m(copy[0], '\0');
	while (copy[len.y])
		len.y++;
	get_player_pos(copy, &player_pos);
	flood_fill(copy, player_pos.y, player_pos.x, &len);
	if (is_valid(copy))
		return (1);
	return (0);
}

int	map_checker(t_data *so_long)
{
	int		check_sum;
	char	*holder;

	if (!so_long->map_data)
		return (0);
	check_sum = 0;
	check_sum += check_ele(so_long->map_data);
	check_sum += check_limits(so_long->map_data);
	check_sum += check_rectangular(so_long->map_data);
	check_sum += check_surrounded(so_long->map_data);
	check_sum += check_valid_path(so_long->map_copy);
	holder = so_long->holder;
	if (!(holder[0] == '\n' || holder[ft_strlen(holder) - 1] == '\n'))
		check_sum++;
	if (check_sum != 6)
		ft_error(so_long, MAP);
	free(so_long->holder);
	so_long->holder = NULL;
	return (1);
}
