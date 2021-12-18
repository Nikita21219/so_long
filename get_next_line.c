/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:48:27 by bclarind          #+#    #+#             */
/*   Updated: 2021/12/18 12:47:56 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_nl(char **str)
{
	char	*tmp;

	tmp = *str;
	while (*tmp)
		tmp++;
	*tmp = '\n';
	*++tmp = 0;
}

static void	*free_str(char *str)
{
	free(str);
	return (NULL);
}

static char	*get_str(char *buf, char *str)
{
	int			i;
	char		*ptr_to_nl;

	ptr_to_nl = ft_strchr(buf, '\n');
	*ptr_to_nl++ = 0;
	str = ft_strjoin(str, buf);
	if (!str)
		return (NULL);
	i = 0;
	while (*ptr_to_nl)
		buf[i++] = *ptr_to_nl++;
	buf[i] = 0;
	add_nl(&str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[1];
	char		*str;
	int			len_readed_bytes;

	if (fd < 0)
		return (NULL);
	len_readed_bytes = 1;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	if (ft_strchr(buf, '\n'))
		return (get_str(buf, str));
	str = ft_strjoin(str, buf);
	while (len_readed_bytes)
	{
		len_readed_bytes = read(fd, buf, 1);
		if (len_readed_bytes <= 0 && !*str)
			return (free_str(str));
		buf[len_readed_bytes] = 0;
		if (ft_strchr(buf, '\n'))
			return (get_str(buf, str));
		str = ft_strjoin(str, buf);
	}
	return (str);
}
