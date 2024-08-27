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

void	start_game(mlx_t *mlx, t_map *map, t_player *player)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, S_W, S_H);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		return ;
}
