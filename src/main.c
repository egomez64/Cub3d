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
	mlx_t		*mlx;
	t_player	player;
	t_map		map;

	init_map(&map);
	init_player(&player);
	mlx = mlx_init(S_W, S_H, "Cub3d", 0);
	// pars();
	start_game(mlx, &map, &player);
	// map_start();
	// hook();
	// raycasting();
	// loop();
	// free_all();
}
