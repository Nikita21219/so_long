/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:29:54 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 13:42:29 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>

typedef struct s_data {
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	char	**map;
}	t_data;

typedef struct s_enemy {
	int		x;
	int		y;
}	t_enemy;

int		map_draw(t_data *data);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
int		get_rows(char *map_path);
int		get_map_rows(char **map);
int		exit_from_game(t_data *data);
int		is_map_not_valid(char *map_path);
void	check_collisions(t_data *data);
void	enemy_gen(t_data *data);
int		animate(t_data *data);
int		is_not_allow(int x, int y, t_data *data);
void	*free_mem(char **mem, int fd, char *str);
void	free_map(char **map);
int		free_win(t_data *data);
char	**get_map(char *map_path);
void	pers_move(t_data *data, char way);
int		keypress_handle(int keycode, t_data *data);
void	empty_space_draw(t_data *data);
int		get_x(t_data *data);
int		get_y(t_data *data);
int		is_allow_exit(t_data *data, char way);
void	hero_draw(t_data *data);
void	gnl_with_free(char **str, int fd);
int		unknown_key(char *map_path);
int		is_not_left_collectible(t_data *data);

#endif