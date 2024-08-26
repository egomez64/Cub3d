/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:16:22 by egomez            #+#    #+#             */
/*   Updated: 2024/08/19 15:16:25 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_player
{
    float 	x;
    float 	y;
	int		fov;
	char	orientation;
}   		t_player;

typedef	struct s_map
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;

	char	*f_color;
	char	*c_color;
	char	**map;
}			t_map;

typedef struct	s_ray
{
	float	impact_x;
	float	impact_y;
	float	angle;
}			t_ray;

void	init_map(t_map *map);
void	init_player(t_player *player);

int		parsing(t_map map, t_player player);

void	map_to_mlx(mlx_t *mlx, t_map *map, t_player *player);

void	init_hooks(mlx_t *mlx);

t_ray	*init_ray(t_player *player);
void	raycasting(t_map *map, t_player *player);

void	free_all(t_map *map, mlx_t *mlx);
#endif