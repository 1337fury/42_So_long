/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:57:29 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/05 19:54:55 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ele(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' \
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_m(map[i], '\0');
	i++;
	while (map[i])
	{
		if (len != ft_strlen_m(map[i], '\0'))
			return (0);
		i++;
	}
	return (1);
}

int	check_surrounded(char **map)
{
	int		i;
	t_len	len;

	len.x = ft_strlen_m(map[0], '\0');
	len.y = 0;
	while (map[len.y])
		len.y++;
	i = 0;
	while (map[0][i] != '\0')
		if (map[0][i++] != '1')
			return (0);
	i = -1;
	while (++i < len.y - 1)
		if (map[i][0] != '1' || map[i][len.x - 1] != '1')
			return (0);
	i = -1;
	while (map[len.y - 1][++i] != '\0')
		if (map[len.y - 1][i] != '1')
			return (0);
	return (1);
}

void	init_ele(t_ele *element)
{
	element->exit = 0;
	element->collectible = 0;
	element->player = 0;
}

int	check_limits(char **map)
{
	int		i;
	int		j;
	t_ele	element;

	init_ele(&element);
	i = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'E')
				element.exit++;
			else if (map[i][j] == 'C')
				element.collectible++;
			else if (map[i][j] == 'P')
				element.player++;
		}
	}
	if (element.exit == 1 && element.collectible >= 1 && element.player == 1)
		return (1);
	return (0);
}
