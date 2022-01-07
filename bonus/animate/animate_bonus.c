/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:20:20 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/07 16:13:08 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	collectible_draw(t_data *data, char *path, int x, int y)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(data->mlx, "./img/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50);
	img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50);
}

void	search_collectible(t_data *data, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				collectible_draw(data, path, j, i);
			j++;
		}
		i++;
	}
}

int	animate(t_data *data)
{
	static int	i = 0;

	if (i % 2000 == 0)
		search_collectible(data, "./img/collectible1.xpm");
	if (i % 4000 == 0)
		search_collectible(data, "./img/collectible2.xpm");
	i++;
	return (0);
}
