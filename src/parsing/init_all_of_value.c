/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_of_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:49:19 by bdany             #+#    #+#             */
/*   Updated: 2024/10/20 16:37:44 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void init_all_of_value(t_game *data)
{
	data->map.line = 0;
	data->texture.direction = 0;
	data->player.orientation = 0;
	data->map.start_map = 0;
	data->ceilfloor.ceil_color = 0;
	data->ceilfloor.floor_color = 0;
	data->texture.count_c = 0;
	data->texture.count_f = 0;
	data->texture.count_no = 0;
	data->texture.count_we = 0;
	data->texture.count_so = 0;
	data->texture.count_ea = 0;
}

// void init_texture(t_text *texture)
// {
// 	texture->count_c = 0;
// 	texture->count_f = 0;
// 	texture->count_no = 0;
// 	texture->count_we = 0;
// 	texture->count_so = 0;
// 	texture->count_ea = 0;
// }
