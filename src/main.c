/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/08/19 14:43:33 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main()
{
	t_game	game;

	init_map(&game.map);
	init_player(&game.player);
	init_text(&game);
	// pars();
	start_game(&game, &game.map, &game.player);
	mlx_loop_hook(game.map.mlx, update, &game);
	mlx_close_hook(game.map.mlx, (mlx_closefunc)free_all, &game);
	mlx_loop(game.map.mlx);
}
