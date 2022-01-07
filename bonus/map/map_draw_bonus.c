/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:38 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 14:42:35 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	subject_draw(char *path, t_data *data)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(data->mlx, "./img/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, data->x, data->y);
	img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, data->x, data->y);
}

int	get_rows(char *map_path)
{
	int		count;
	int		fd;
	char	*str;

	count = 0;
	fd = open(map_path, O_RDONLY);
	str = get_next_line(fd);
	while (*str == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str && *str != '\n')
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	return (count);
}

int	map_draw(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->y = 0;
	while (data->map[++i])
	{
		j = -1;
		data->x = 0;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0')
				subject_draw("./img/empty.xpm", data);
			else if (data->map[i][j] == '1')
				subject_draw("./img/wall.xpm", data);
			else if (data->map[i][j] == 'E')
				subject_draw("./img/exit.xpm", data);
			else if (data->map[i][j] == 'P')
				subject_draw("./img/start.xpm", data);
			data->x += 50;
		}
		data->y += 50;
	}
	mlx_string_put(data->mlx, data->win, 0, 0, 555, "0");
	return (0);
}
