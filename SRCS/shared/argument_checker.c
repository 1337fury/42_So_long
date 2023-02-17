/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:46 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/02/06 08:57:55 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argument_checker(t_data *so_long, char *av)
{
	int	i;

	if (!av)
		ft_error(so_long, -1);
	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b'
		&& av [i - 3] == '.')
		return (1);
	ft_error(so_long, ARGS);
	return (0);
}
