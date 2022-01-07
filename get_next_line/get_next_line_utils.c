/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:16:34 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 14:55:19 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s && *s++ != '\n')
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (NULL);
}

void	*ft_bzero(void *destination, size_t n)
{
	size_t	i;
	char	*tmp_buf;

	tmp_buf = destination;
	i = 0;
	while (i < n)
	{
		*tmp_buf = '\0';
		tmp_buf++;
		i++;
	}
	return (destination);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem)
		ft_bzero(mem, count * size);
	else
		return (NULL);
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	char	*res;
	char	*ptr_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr_s1 = (char *) s1;
	mem = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 2);
	if (!(mem))
	{
		free((char *) s1);
		return (NULL);
	}
	res = mem;
	while (*s1)
		*mem++ = *s1++;
	while (*s2)
		*mem++ = *s2++;
	*mem = 0;
	free((char *) ptr_s1);
	return (res);
}
