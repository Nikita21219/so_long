/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:17:56 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 16:13:34 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	get_map_rows(char **map)
{
	int	res;

	res = 0;
	while (*map++)
		res++;
	return (res);
}

int	is_not_allow(int x, int y, t_data *data)
{
	if (!x || !y)
		return (1);
	if (data->map[y][x] == '0')
		return (0);
	return (1);
}
