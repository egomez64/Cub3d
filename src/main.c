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
	t_player	player;
	t_map		map;

	init_map(&map);
	init_player(&player);
	// pars();
	start_game(map.mlx, &map, &player);
	// map_start();
	// hook();
	// raycasting();
	mlx_loop(map.mlx);
	// free_all();
}
