/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:32:28 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 16:13:54 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_count_rows(char *map_path)
{
	int		fd;
	int		res;
	char	c;

	fd = open(map_path, O_RDONLY);
	res = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			res++;
	}
	close(fd);
	return (res + 1);
}

int	get_count_colomns(char *map_path)
{
	int		fd;
	char	c;
	int		res;

	fd = open(map_path, O_RDONLY);
	res = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			return (res);
		res++;
	}
	close(fd);
	return (res);
}

int	chek_new_line(char **str, int fd)
{
	if (**str == '\n')
	{
		free(*str);
		*str = get_next_line(fd);
		return (1);
	}
	return (0);
}

char	**malloc_map(char *map_path)
{
	int		fd;
	char	**res;
	char	**mem;
	char	*str;

	mem = ft_calloc(sizeof(char *), get_count_rows(map_path) + 1);
	if (!mem)
		return (NULL);
	res = mem;
	fd = open(map_path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if (chek_new_line(&str, fd))
			continue ;
		*mem++ = ft_calloc(sizeof(char), get_count_colomns(map_path) + 1);
		if (!*(mem - 1))
			return (free_mem(res, fd, str));
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (res);
}

char	**get_map(char *map_path)
{
	char	**res;
	char	*str;
	int		fd;
	int		i;

	if (is_map_not_valid(map_path))
		return (NULL);
	i = 0;
	res = malloc_map(map_path);
	if (!res)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if (*str != '\n')
			res[i++] = str;
		else
			free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (res);
}
