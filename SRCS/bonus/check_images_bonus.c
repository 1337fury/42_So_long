/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:29:31 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/07 12:49:47 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_error(t_data *so_long)
{
	if (so_long->wall != NULL)
		mlx_destroy_image(so_long->mlx, so_long->wall);
	if (so_long->space != NULL)
		mlx_destroy_image(so_long->mlx, so_long->space);
	if (so_long->exit != NULL)
		mlx_destroy_image(so_long->mlx, so_long->exit);
	if (so_long->items != NULL)
		mlx_destroy_image(so_long->mlx, so_long->items);
	if (so_long->player != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player);
	if (so_long->enemies != NULL)
		mlx_destroy_image(so_long->mlx, so_long->enemies);
	free_double(so_long->map_data);
	free_double(so_long->map_copy);
	mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->mlx);
	free(so_long);
	so_long = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

void	check_images_bonus(t_data *so_long)
{
	if (so_long->wall == NULL || so_long->space == NULL \
		|| so_long->exit == NULL || so_long->items == NULL \
		|| so_long->player == NULL || so_long->enemies == NULL)
		images_error(so_long);
}
