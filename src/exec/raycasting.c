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

t_ray	*init_ray(t_player *player)
{
	//return (tab_of_ray[as_much_as_need_with_fov]);
}

void	raycasting(t_map *map, t_player *player)
{
	double	ray_x;
	double	ray_y;
	double	camera_x;
	int		x;

	x = 0;
	while (x < S_W)
	{
		camera_x = 2 * x / (double)S_W -1;
		ray_x = player->orientation_x + player->plane_x * camera_x;
		ray_x = player->orientation_y + player->plane_y * camera_x;
		x++;
	}
}
