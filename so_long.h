/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:29:54 by bclarind          #+#    #+#             */
/*   Updated: 2021/12/18 20:50:41 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data {
	int		x;
	int		y;
	void *mlx_ptr;
	void *win_ptr;
}	t_data;

// typedef struct	s_vars {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		x;
// 	int 	y;
// }				t_vars;

int		map_draw(char *map_path, t_data *data);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

#endif