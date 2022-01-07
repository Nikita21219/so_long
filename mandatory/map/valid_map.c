/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:13:18 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 14:41:30 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

int	free_str(char *str, int return_val)
{
	free(str);
	return (return_val);
}

int	is_map_not_closed(char *map_path)
{
	int		fd;
	char	*str;
	int		count_rows;

	fd = open(map_path, O_RDONLY);
	count_rows = get_rows(map_path);
	if (count_rows <= 0 || (count_rows > 0 && count_rows < 3))
		return (1);
	str = get_next_line(fd);
	while (*str == '\n')
		gnl_with_free(&str, fd);
	if (check_first_last_rows(str))
		return (free_str(str, 1));
	str = get_next_line(fd);
	while (count_rows-- > 2)
	{
		if ((*str != '1' || *(str + ft_strlen(str) - 1) != '1') && *str != '\n')
			return (free_str(str, 1));
		gnl_with_free(&str, fd);
	}
	if (check_first_last_rows(str))
		return (free_str(str, 1));
	return (free_str(str, 0));
}

int	is_missing_item(char *map_path)
{
	int		fd;
	char	c;
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
	int		count_ch;
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line && *line == '\n')
		gnl_with_free(&line, fd);
	count_ch = ft_strlen(line);
	while (line)
	{
		if (count_ch != ft_strlen(line) && *line != '\n')
		{
			free(line);
			return (1);
		}
		line = get_next_line(fd);
	}
	if (is_map_not_closed(map_path) || is_missing_item(map_path))
		return (1);
	if (unknown_key(map_path))
		return (1);
	return (0);
}
