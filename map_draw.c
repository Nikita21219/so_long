/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:38 by bclarind          #+#    #+#             */
/*   Updated: 2021/12/17 22:24:46 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	subject_draw(char *relative_path, void *mlx, void *mlx_win, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
}

void	map_draw(char *map_path, void *mlx_ptr, void *win_ptr)
{
	char 	c;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(map_path, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			y += 50;
			x = 0;
			continue ;
		}
		else if (c == '0')
			subject_draw("./images/empty_space.xpm", mlx_ptr, win_ptr, x, y);
		else if (c == '1')
			subject_draw("./images/wall.xpm", mlx_ptr, win_ptr, x, y);
		else if (c == 'C')
			subject_draw("./images/collectible.xpm", mlx_ptr, win_ptr, x, y);
		else if (c == 'E')
			subject_draw("./images/exit.xpm", mlx_ptr, win_ptr, x, y);
		else if (c == 'P')
			subject_draw("./images/starting_position.xpm", mlx_ptr, win_ptr, x, y);
		x += 50;
	}
}
