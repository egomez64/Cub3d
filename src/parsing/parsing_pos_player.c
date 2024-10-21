/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pos_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:32 by bdany             #+#    #+#             */
/*   Updated: 2024/10/20 16:53:00 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_pos_player(t_game *pos)
{
	int	x;
	int	y;
	int flag;

	y = 0;
	flag = 0;
	while (pos->map.map[y])
	{
		x = 0;
		while (pos->map.map[y][x])
		{

			if (pos->map.map[y][x] == 'N' || pos->map.map[y][x] == 'S' || pos->map.map[y][x] == 'E' || pos->map.map[y][x] == 'W')
			{
				flag = 1;
				pos->player.x = x + 0.5;
				pos->player.y = y + 0.5;
				pos->player.orientation = pos->map.map[y][x];
				pos->map.map[y][x] = 48;
				return ;
			}
			x++;
		}
		y++;
	}
	if (!flag)
		exit_error("error: no player position found\n");
}

