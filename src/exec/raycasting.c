/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:17 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:51:18 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	raycasting(t_map *map, t_player *player, t_game *game)
{
	int	x;
	t_ray	ray;

	x = 0;
	while (x < S_W)
	{
		draw_ceiling_floor(game, x, S_H / 2, S_H, get_color_rgba(0, 255, 0, 255));
		draw_ceiling_floor(game, x, 0, S_H / 2, get_color_rgba(0, 0, 255, 255));
		ray.camera_x = 2 * x / (double)S_W -1;
		ray.ray_x = player->dir_x + player->plane_x * ray.camera_x;
		ray.ray_y = player->dir_y + player->plane_y * ray.camera_x;
		ray.map_x = (int)player->x;
		ray.map_y = (int)player->y;
		if (ray.ray_x == 0)
			ray.deltadist_x = 1e30;
		else
			ray.deltadist_x = fabs(1 / ray.ray_x);
		if (ray.ray_y == 0)
			ray.deltadist_y = 1e30;
		else
			ray.deltadist_y = fabs(1 / ray.ray_y);
		if (ray.ray_x < 0)
		{
			ray.step_x = -1;
			ray.sidedist_x = (player->x - ray.map_x) * ray.deltadist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.sidedist_x = (ray.map_x + 1 - player->x) * ray.deltadist_x;
		}
		if (ray.ray_y < 0)
		{
			ray.step_y = -1;
			ray.sidedist_y = (player->y - ray.map_y) * ray.deltadist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.sidedist_y = (ray.map_y + 1 - player->y) * ray.deltadist_y;
		}
		ray.hit = 0;
		while (ray.hit == 0)
		{
			if (ray.sidedist_x < ray.sidedist_y)
			{
				ray.sidedist_x += ray.deltadist_x;
				ray.map_x += ray.step_x;
				ray.side = 0;
			}
			else
			{
				ray.sidedist_y += ray.deltadist_y;
				ray.map_y += ray.step_y;
				ray.side = 1;
			}
			if (map->map[ray.map_x][ray.map_y] == '1')
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perpwalldist = ray.sidedist_x - ray.deltadist_x;
		else
			ray.perpwalldist = ray.sidedist_y - ray.deltadist_y;
		ray.lineheight = (int)(S_H / ray.perpwalldist);
		ray.draw_start = -ray.lineheight / 2 + S_H / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.lineheight / 2 + S_H / 2;
		if (ray.draw_end >= S_H)
			ray.draw_end = S_H - 1;
		game->texture.tex_num = game->map.map[game->ray.map_x][game->ray.map_y] - 1;
		if (ray.side == 1)
			game->ray.wall_x = game->player.x + game->ray.perpwalldist * game->ray.ray_x;
		else
			game->ray.wall_x = game->player.y + game->ray.perpwalldist * game->ray.ray_y;
		game->ray.wall_x -= floor((game->ray.wall_x));
		game->texture.tex_x = (int)(game->ray.wall_x * (double)T_W);
		if (game->ray.side == 0 && game->ray.ray_x > 0)
			game->texture.tex_x = T_W - game->texture.tex_x - 1;
		if (game->ray.side == 1 && game->ray.ray_x < 0)
			game->texture.tex_x = T_W - game->texture.tex_x - 1;
		game->texture.step = 1.0 * T_H / game->ray.lineheight;
		game->texture.tex_pos = (game->ray.draw_start - S_H + game->ray.lineheight / 2) * game->texture.step;
		int y = game->ray.draw_start;
		while (y < game->ray.draw_end)
		{
			game->texture.tex_y = (int)game->texture.tex_pos & (T_H - 1);
			game->texture.tex_pos += game->texture.step;
			game->texture.color = game->texture.texture[game->texture.tex_num][T_H * game->texture.tex_y + game->texture.tex_x];
			if (game->ray.side == 1)
				game->texture.color = (game->texture.color >> 1) & 8355711;
			game->texture.buff[y][x] = game->texture.color;
			mlx_put_pixel(game->map.img, x, y, game->texture.color);
			y++;
		}
		x++;
	}
}
