/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:38:02 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 16:10:27 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_allow_exit(t_data *data, char way)
{
	if (way == 'l' && data->map[get_y(data) / 50][get_x(data) / 50 - 1] == 'E')
		if (is_not_left_collectible(data))
			return (0);
	if (way == 'r' && data->map[get_y(data) / 50][get_x(data) / 50 + 1] == 'E')
		if (is_not_left_collectible(data))
			return (0);
	if (way == 'd' && data->map[get_y(data) / 50 + 1][get_x(data) / 50] == 'E')
		if (is_not_left_collectible(data))
			return (0);
	if (way == 'u' && data->map[get_y(data) / 50 - 1][get_x(data) / 50] == 'E')
		if (is_not_left_collectible(data))
			return (0);
	return (1);
}

int	is_allow_move(char way, t_data *data)
{
	int	x;
	int	y;

	x = data->x / 50;
	y = data->y / 50;
	if (way == 'l' && data->map[y][x - 1] != '1' && is_allow_exit(data, way))
		return (1);
	if (way == 'r' && data->map[y][x + 1] != '1' && is_allow_exit(data, way))
		return (1);
	if (way == 'u' && data->map[y - 1][x] != '1' && is_allow_exit(data, way))
		return (1);
	if (way == 'd' && data->map[y + 1][x] != '1' && is_allow_exit(data, way))
		return (1);
	return (0);
}

int	valid_keycode(int keycode)
{
	if (keycode == 2 || keycode == 13 || keycode == 1 || keycode == 0)
		return (1);
	if (keycode == 124 || keycode == 123 || keycode == 126 || keycode == 125)
		return (1);
	return (0);
}

void	check_collisions(t_data *data)
{
	if (data->map[data->y / 50][data->x / 50] == 'E')
		exit_from_game(data);
	if (data->map[data->y / 50][data->x / 50] == 'C')
		data->map[data->y / 50][data->x / 50] = '0';
}

int	keypress_handle(int keycode, t_data *data)
{
	if (valid_keycode(keycode))
	{
		if ((keycode == 2 || keycode == 124) && is_allow_move('r', data))
			pers_move(data, 'r');
		else if ((keycode == 13 || keycode == 126) && is_allow_move('u', data))
			pers_move(data, 'u');
		else if ((keycode == 1 || keycode == 125) && is_allow_move('d', data))
			pers_move(data, 'd');
		else if ((keycode == 0 || keycode == 123) && is_allow_move('l', data))
			pers_move(data, 'l');
		hero_draw(data);
		check_collisions(data);
	}
	else if (keycode == 53)
		exit_from_game(data);
	return (0);
}
