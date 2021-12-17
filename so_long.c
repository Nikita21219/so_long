/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:47:03 by bclarind          #+#    #+#             */
/*   Updated: 2021/12/17 22:28:15 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_with_or_height(char *map_path, int flag)
{
	int		fd;
	int		max;
	int		i;
	char	c;

	max = 0;
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (flag)
	{
		while (read(fd, &c, 1))
		{
			if (c == '\n')
				i += 50;
		}
		i += 50;
	}
	else
	{
		while (read(fd, &c, 1))
		{
			// if (c == '\n')
			// {
			// 	if (i > max)
			// 		max = i;
			// }
			// else
			// 	i += 50;
			if (c == '\n')
				return (i);
			i += 50;
		}
		// return (max);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	(void) argv;
	if (argc != 2)
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, get_with_or_height(argv[1], 0), get_with_or_height(argv[1], 1), "Hello world!"); //    
	if (mlx_win == NULL)
		free(mlx_win);
	map_draw(argv[1], mlx, mlx_win);
	mlx_loop(mlx);
}
