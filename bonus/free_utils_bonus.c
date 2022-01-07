/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:23:13 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 14:42:50 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*free_mem(char **mem, int fd, char *str)
{
	int	i;

	i = 0;
	while (mem[i])
		free(mem[i++]);
	free(mem);
	close(fd);
	free(str);
	return (NULL);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	free_win(t_data *data)
{
	free(data->win);
	return (0);
}

void	gnl_with_free(char **line, int fd)
{
	free(*line);
	*line = get_next_line(fd);
}
