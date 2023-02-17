/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:41:05 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/06 11:59:26 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_dims(t_data *so_long, int x, int y)
{
	if (x > 28)
		ft_error(so_long, MAP_D);
	if (y > 15)
		ft_error(so_long, MAP_D);
}

int	get_map_and_dims(t_data *so_long, char *path)
{
	int			fd;
	char		*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	so_long->dims.width = ft_strlen_m(line, '\n');
	while (line != NULL)
	{
		if (line[0] == '\n')
			ft_error(so_long, MAP);
		so_long->holder = ft_strjoin_m(so_long->holder, line);
		so_long->dims.height++;
		free(line);
		line = get_next_line(fd);
	}
	check_dims(so_long, so_long->dims.width, so_long->dims.height);
	so_long->map_data = ft_split(so_long->holder, '\n');
	so_long->map_copy = ft_split(so_long->holder, '\n');
	close(fd);
	return (1);
}
