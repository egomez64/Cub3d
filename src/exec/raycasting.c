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

void	raycasting(t_map *map, t_player *player)
{
	int	x;
	t_ray	ray;

	x = 0;
	while (x < S_W)
	{
		verline(map->img, x, S_H / 2, S_H, get_color_rgba(0, 255, 0, 255));
		verline(map->img, x, 0, S_H / 2, get_color_rgba(0, 0, 255, 255));
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
		uint32_t color;
		if (ray.side == 1)
			color = get_color_rgba(255 / 2, 0, 0, 255);
		else
			color = get_color_rgba(255, 0, 0, 255);
		verline(map->img, x, ray.draw_start, ray.draw_end, color);
		x++;
	}
}
