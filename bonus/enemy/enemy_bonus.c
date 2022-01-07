/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:10:59 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 16:13:32 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	check_collisions(t_data *data)
{
	if (data->map[data->y / 50][data->x / 50] == 'e')
		exit_from_game(data);
	if (data->map[data->y / 50][data->x / 50] == 'E')
		exit_from_game(data);
	if (data->map[data->y / 50][data->x / 50] == 'C')
		data->map[data->y / 50][data->x / 50] = '0';
}

int	ft_randint(int min, int max)
{
	int	result;

	result = (rand() % (max - min + 1)) + min;
	return (result);
}

int	get_max_count_enemies(t_data *data)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	enemy_draw(int x, int y, t_data *data)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(data->mlx, "./img/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50);
	img = mlx_xpm_file_to_image(data->mlx, "./img/enemy.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50);
}

void	enemy_gen(t_data *data)
{
	int	x;
	int	y;
	int	count_enemies;
	int	max_count_enemies;

	max_count_enemies = get_max_count_enemies(data) / 8;
	if (!max_count_enemies)
		return ;
	count_enemies = ft_randint(1, max_count_enemies);
	while (count_enemies-- > 0)
	{
		x = ft_randint(1, ft_strlen(data->map[0]));
		y = ft_randint(1, get_map_rows(data->map) - 1);
		while (is_not_allow(x, y, data))
		{
			x = ft_randint(1, ft_strlen(data->map[0]));
			y = ft_randint(1, get_map_rows(data->map) - 1);
			srand(time(NULL));
		}
		enemy_draw(x, y, data);
		data->map[y][x] = 'e';
	}
}
