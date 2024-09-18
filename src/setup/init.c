/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:49:23 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:49:25 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void    init_map(t_map *map)
{
    //tempo
	map->map = malloc(8 * sizeof(char *));
	map->map[0] = ft_strdup("1111111");
	map->map[1] = ft_strdup("1100001");
	map->map[2] = ft_strdup("1000001");
	map->map[3] = ft_strdup("1000001");
	map->map[4] = ft_strdup("1000001");
	map->map[5] = ft_strdup("1000001");
	map->map[6] = ft_strdup("1111111");
	map->map[7] = NULL;
	map->mlx = mlx_init(S_W, S_H, "Cub3d", 0);
	//tempo
}

void    init_player(t_player *player)
{
	//tempo
	player->x = 2.5;
	player->y = 4;
	player->plane_x = 1;
	player->plane_y = 0;
	player->dir_x = 0;
	player->dir_y = -1;
	//tempo
}
