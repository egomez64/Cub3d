/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:00 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:51:01 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	verline(mlx_image_t *img, int x, int draw_start, int draw_end, uint32_t color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(img, x, y, color);
		y++;
	}
}

void	start_game(mlx_t *mlx, t_map *map, t_player *player)
{
	map->img = mlx_new_image(mlx, S_W, S_H);
	if (!map->img)
		return ;
	if (mlx_image_to_window(mlx, map->img, 0, 0) < 0)
		return ;
	raycasting(map, player);
}
