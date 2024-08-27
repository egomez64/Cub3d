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
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define S_W 1900
# define S_H 1000
# define SPEED 5

typedef struct s_player
{
    int		x;
    int 	y;
	double	plane_x;
	double	plane_y;
	int		orientation_x;
	int		orientation_y;
}   	t_player;

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

void	start_game(mlx_t *mlx, t_map *map, t_player *player);

void	init_hooks(mlx_t *mlx);

t_ray	*init_ray(t_player *player);
void	raycasting(t_map *map, t_player *player);

void	free_all(t_map *map, mlx_t *mlx);
#endif