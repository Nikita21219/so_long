/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:47:03 by bclarind          #+#    #+#             */
/*   Updated: 2021/12/18 16:03:35 by bclarind         ###   ########.fr       */
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
			if (c == '\n')
				return (i);
			i += 50;
		}
	}
	return (i);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void) argv;
	if (argc != 2)
		return (1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, get_with_or_height(argv[1], 0), get_with_or_height(argv[1], 1), "My game");
	if (win_ptr == NULL)
		free(win_ptr);
	if (map_draw(argv[1], mlx_ptr, win_ptr))
	{
		printf("Error\n");
		return (1);
	}
	mlx_loop(mlx_ptr);
}
