/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:24:17 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/03 16:23:38 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_bonus(t_data *so_long)
{
	free_double(so_long->map_data);
	free_double(so_long->map_copy);
	mlx_destroy_image(so_long->mlx, so_long->wall);
	mlx_destroy_image(so_long->mlx, so_long->space);
	mlx_destroy_image(so_long->mlx, so_long->exit);
	mlx_destroy_image(so_long->mlx, so_long->items);
	mlx_destroy_image(so_long->mlx, so_long->player);
	mlx_destroy_image(so_long->mlx, so_long->enemies);
	mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->mlx);
	exit(0);
	return (0);
}
