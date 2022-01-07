/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pers_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:39:59 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 16:14:01 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	hero_draw(t_data *data)
{
	void	*img;
	int		img_w;
	int		img_h;

	empty_space_draw(data);
	img = mlx_xpm_file_to_image(data->mlx, "./img/start.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, data->x, data->y);
	data->map[data->y / 50][data->x / 50] = 'P';
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len_str;
	char	tmp;

	len_str = ft_strlen(str) - 1;
	i = 0;
	while (i < len_str)
	{
		tmp = str[i];
		str[i++] = str[len_str];
		str[len_str--] = tmp;
	}
	return (str);
}

char	*get_str_move(int num)
{
	char	*str_move;
	int		i;

	str_move = ft_calloc(sizeof(char), 11);
	if (!str_move)
		return (NULL);
	i = 0;
	while (num)
	{
		*str_move++ = num % 10 + 48;
		num /= 10;
		i++;
	}
	return (ft_strrev(str_move - i));
}

void	num_move_draw(int num_move, t_data *data)
{
	void	*img;
	char	*str_move;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	str_move = get_str_move(num_move);
	if (!str_move)
		exit_from_game(data);
	mlx_string_put(data->mlx, data->win, 0, 0, 555, str_move);
}

void	pers_move(t_data *data, char way)
{
	static int	num_move = 0;

	empty_space_draw(data);
	data->map[data->y / 50][data->x / 50] = '0';
	if (way == 'r')
		data->x += 50;
	else if (way == 'l')
		data->x -= 50;
	else if (way == 'u')
		data->y -= 50;
	else if (way == 'd')
		data->y += 50;
	check_collisions(data);
	num_move_draw(++num_move, data);
}
