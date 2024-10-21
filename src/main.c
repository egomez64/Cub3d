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

int	main(int argc, char **argv)
{
	t_game	game;
	char **all_map;

	if (argc != 2)
		return(write(2, "error: wrong size of argument\n", 31));
	check_cub_argv(argv[1]);
	init_all_of_value(&game);
	open_fd(&game, argv);
	size_map(&game);
	close(game.fd);
	open_fd(&game, argv);
	all_map = get_map(&game);
	check_for_texture(all_map, &game);
	check_texture(all_map, &game);
	game.map.map = &all_map[game.map.start_map];
	parse_map(&game);
	init_mlx(&game);
	player_orientation(&game);
	init_text(&game);
	start_game(&game);
	mlx_loop_hook(game.map.mlx, (void *)update, (void *)&game);
	mlx_close_hook(game.map.mlx, (mlx_closefunc)free_all, &game);
	mlx_loop(game.map.mlx);
}
