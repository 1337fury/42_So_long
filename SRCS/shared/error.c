/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:00:48 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/06 12:07:19 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_data *so_long, int where)
{
	free_double(so_long->map_data);
	free_double(so_long->map_copy);
	free(so_long->holder);
	free(so_long);
	so_long = NULL;
	if (where == MAP)
		write(2, "Error : Invalid MAP\n", 20);
	else if (where == ARGS)
		write(2, "Error : file extension is invalid\n", 34);
	else if (where == MAP_D)
		write(2, "Error : size of map invalid \n", 29);
	exit(1);
}
