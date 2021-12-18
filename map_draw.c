/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:38 by bclarind          #+#    #+#             */
/*   Updated: 2021/12/18 16:07:39 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	subject_draw(char *relative_path, void *mlx, void *mlx_win, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, "./images/empty_space.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s && *s++ != '\n')
		counter++;
	return (counter);
}

int	get_rows(char *map_path)
{
	int	count;
	int	fd;

	count = 0;
	fd = open(map_path, O_RDONLY);
	while (get_next_line(fd))
		count++;
	return (count);
}

int	check_first_last_rows(char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

int	is_map_not_closed(char *map_path)
{
	int		fd;
	char	*str;
	int		count_rows;

	fd = open(map_path, O_RDONLY);
	count_rows = get_rows(map_path);
	str = get_next_line(fd);
	if (check_first_last_rows(str))
		return (1);
	str = get_next_line(fd);
	while (count_rows-- > 2)
	{
		if ((*str != '1' || *(str + ft_strlen(str) - 1) != '1') && *str != '\n')
			return (1);
		str = get_next_line(fd);
	}
	if (check_first_last_rows(str))
		return (1);
	return (0);
}

int	is_missing_item(char *map_path)
{
	int		fd;
	char 	c;
	int		count_collectible;
	int		count_exit;
	int		count_start_pos;

	fd = open(map_path, O_RDONLY);
	count_collectible = 0;
	count_exit = 0;
	count_start_pos = 0;
	while (read(fd, &c, 1))
	{
		if (c == 'C')
			count_collectible++;
		else if (c == 'E')
			count_exit++;
		else if (c == 'P')
			count_start_pos++;
	}
	if (count_collectible < 1 || count_exit < 1 || count_start_pos < 1)
		return (1);
	return (0);
}

int	is_map_not_valid(char *map_path)
{
	size_t	count_ch;
	char	*str;
	int		fd;

	fd = open(map_path, O_RDONLY);
	count_ch = ft_strlen(get_next_line(fd));
	str = get_next_line(fd);
	while (str)
	{
		if (count_ch != ft_strlen(str))
			return (1);
		str = get_next_line(fd);
	}
	if (is_map_not_closed(map_path) || is_missing_item(map_path))
		return (1);
	return (0);
}

int	keypress_handle(int keycode, void *mlx, void *mlx_win, t_data data)
{
	// if (keysym == XK_Escape)
	// 	mlx_destroy_window(mlx, mlx_win);

	// printf("Keypress: %d\n", keysym);

	// 13-w 0-a 2-d 1-s 53-esc
	(void) mlx;
	(void) mlx_win;
	if (keycode == 13)
	{
		printf("%d\n", data.x);
	}
	return (0);
}

int	map_draw(char *map_path, void *mlx_ptr, void *win_ptr)
{
	char 	c;
	int		fd;
	t_data	data;

	if (is_map_not_valid(map_path))
		return (1);
	data.x = 0;
	data.y = 0;
	fd = open(map_path, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			data.y += 50;
			data.x = 0;
			continue ;
		}
		else if (c == '0')
			subject_draw("./images/empty_space.xpm", mlx_ptr, win_ptr, data.x, data.y);
		else if (c == '1')
			subject_draw("./images/wall.xpm", mlx_ptr, win_ptr, data.x, data.y);
		else if (c == 'C')
			subject_draw("./images/collectible.xpm", mlx_ptr, win_ptr, data.x, data.y);
		else if (c == 'E')
			subject_draw("./images/exit.xpm", mlx_ptr, win_ptr, data.x, data.y);
		else if (c == 'P')
			subject_draw("./images/starting_position.xpm", mlx_ptr, win_ptr, data.x, data.y);
		data.x += 50;
	}
	mlx_key_hook(win_ptr, &keypress_handle, &data);
	return (0);
}
