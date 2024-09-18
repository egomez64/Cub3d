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

# define S_W 1080
# define S_H 720
# define SPEED 0.06
# define WALL_DISTANCE 5

typedef struct s_player
{
    double	x;
    double	y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
}   	t_player;

typedef	struct s_map
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*f_color;
	char	*c_color;
	mlx_t		*mlx;
	mlx_image_t	*img;
	char	**map;
}			t_map;

typedef struct	s_ray
{
	double	ray_x;
	double	ray_y;
	double	camera_x;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	t_ray		ray;
}				t_game;

void	init_map(t_map *map);
void	init_player(t_player *player);

void	parsing(t_map map, t_player player);

void	start_game(mlx_t *mlx, t_map *map, t_player *player);

void	move(t_game *game);
void 	update(void *param);

t_ray	*init_ray(t_player *player);
void	raycasting(t_map *map, t_player *player);
void	verline(mlx_image_t *img, int x, int draw_start, int draw_end, uint32_t color);

void	free_all(t_map *map, mlx_t *mlx);
#endif