/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:47:03 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 14:43:05 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	empty_space_draw(t_data *data)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(data->mlx, "./img/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, data->x, data->y);
}

int	get_width(char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (*line != '\n')
			return (ft_strlen(line) * 50);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	get_height(char *map_path)
{
	int		fd;
	int		max;
	int		i;
	char	*line;

	max = 0;
	i = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			i += 50;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	print_error(char *mes)
{
	printf("Error\n");
	printf("%s", mes);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		width;

	if (argc != 2)
		return (print_error("need 2 number of parameters\n"));
	data.mlx = mlx_init();
	width = get_width(argv[1]);
	if (width == -1)
		return (print_error("read() - error\n"));
	data.win = mlx_new_window(data.mlx, width, get_height(argv[1]), "so long");
	if (!data.win)
		return (free_win(&data));
	data.map = get_map(argv[1]);
	if (!data.map)
		return (print_error("Map is not valid or memory allocated fail\n"));
	map_draw(&data);
	enemy_gen(&data);
	data.x = get_x(&data);
	data.y = get_y(&data);
	mlx_key_hook(data.win, keypress_handle, &data);
	mlx_hook(data.win, 17, 0L, exit_from_game, &data);
	mlx_loop_hook(data.mlx, animate, &data);
	mlx_loop(data.mlx);
	return (0);
}
