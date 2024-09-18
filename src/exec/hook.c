/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:06 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:51:07 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void 	update(void *param)
{
	t_game *game;

	game = param;
	move(game);
}

void	move(t_game *game)
{
	int x;
	int y;

	if (mlx_is_key_down(game->map.mlx, MLX_KEY_W))
	{
		x = game->player.x + (game->player.dir_x + WALL_DISTANCE * game->player.dir_x) * SPEED;
		y = game->player.y + (game->player.dir_y + WALL_DISTANCE * game->player.dir_y) * SPEED;

		if(game->map.map[x][(int)game->player.y] == '0')
			game->player.x += game->player.dir_x * SPEED;
		if(game->map.map[(int)game->player.x][y] == '0')
			game->player.y += game->player.dir_y * SPEED;
	}
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_S))
	{
		x = game->player.x - (game->player.dir_x + WALL_DISTANCE * game->player.dir_x) * SPEED;
		y = game->player.y - (game->player.dir_y + WALL_DISTANCE * game->player.dir_y) * SPEED;

		if(game->map.map[x][(int)game->player.y] == '0')
			game->player.x -= game->player.dir_x * SPEED;
		if(game->map.map[(int)game->player.x][y] == '0')
			game->player.y -= game->player.dir_y * SPEED;
	}
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_A))
	{
		x = game->player.x + (game->player.dir_y + WALL_DISTANCE * game->player.dir_y) * SPEED;
		y = game->player.y - (game->player.dir_x + WALL_DISTANCE * game->player.dir_x) * SPEED;

		if(game->map.map[x][(int)game->player.y] == '0')
			game->player.x += game->player.dir_y * SPEED;
		if(game->map.map[(int)game->player.x][y] == '0')
			game->player.y -= game->player.dir_x * SPEED;
	}
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_D))
	{
		x = game->player.x - (game->player.dir_y + WALL_DISTANCE * game->player.dir_y) * SPEED;
		y = game->player.y + (game->player.dir_x + WALL_DISTANCE * game->player.dir_x) * SPEED;

		if(game->map.map[x][(int)game->player.y] == '0')
			game->player.x -= game->player.dir_y * SPEED;
		if(game->map.map[(int)game->player.x][y] == '0')
			game->player.y += game->player.dir_x * SPEED;
	}
	raycasting(&game->map, &game->player);
}
