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
	// pars();
	start_game(game.map.mlx, &game.map, &game.player);
	// map_start();
	// mlx_key_hook(game.map.mlx, (void *)move, &game);
	mlx_loop_hook(game.map.mlx, update, &game);
	mlx_loop(game.map.mlx);
	// free_all();
}
