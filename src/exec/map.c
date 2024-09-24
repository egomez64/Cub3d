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

uint32_t	get_color_rgba(int r, int g, int b, int a)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_ceiling_floor(t_game *game, int x, int draw_start, int draw_end, uint32_t color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(game->map.img, x, y, color);
		y++;
	}
}

/*void	draw_wall(t_game *game, int x, int draw_start, int draw_end)
{
	int	y;
	uint32_t color;
	uint32_t coord;

	y = draw_start;
	while (y < draw_end)
	{
		coord = (game->texture.north->width * game->ray.ray_y + (game->texture.north->width
				- game->ray.ray_x)) * 4;
		color = get_color_rgba(game->texture.north->pixels[coord],
			game->texture.north->pixels[coord + 1],
			game->texture.north->pixels[coord + 2],
			game->texture.north->pixels[coord + 3]);
		mlx_put_pixel(game->map.img, x, y, color);
		y++;
	}
}*/

void	start_game(t_game *game, t_map *map, t_player *player)
{
	map->img = mlx_new_image(game->map.mlx, S_W, S_H);
	if (!map->img)
		return ;
	if (mlx_image_to_window(game->map.mlx, map->img, 0, 0) < 0)
		return ;
	raycasting(map, player, game);
}
