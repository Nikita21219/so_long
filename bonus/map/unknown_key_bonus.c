/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:06:56 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 14:42:37 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_search_char(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	unknown_key(char *map_path)
{
	int		fd;
	char	c;

	fd = open(map_path, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (ft_search_char("01CEP\n", c))
			continue ;
		else
			return (1);
	}
	return (0);
}
