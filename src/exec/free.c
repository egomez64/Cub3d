/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:33 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:51:34 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_all(t_game *game)
{
	if (game->map.img)
		mlx_delete_image(game->map.mlx, game->map.img);
	if (game->map.mlx)
		mlx_close_window(game->map.mlx);
}
