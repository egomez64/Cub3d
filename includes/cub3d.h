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
# define T_W 64
# define T_H 64
# define SPEED 0.06
# define ROTATE_SPEED 0.05
# define WALL_DISTANCE 5

typedef	struct s_text
{
	mlx_image_t	*texture[4];
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	color;
}				t_text;

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
	double	wall_x;
}			t_ray;

typedef struct s_game
{
	int			x;
	int			y;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_text		texture;
}				t_game;

void		init_map(t_game *game);
void		init_player(t_game *game);
void		init_text(t_game *game);

void		parsing(t_map map, t_player player);

void		start_game(t_game *game);

void		move(t_game *game);
void 		update(t_game *game);
uint32_t	get_color_rgba(int r, int g, int b, int a);

void		raycasting(t_game *game);
void		raycasting2(t_game *game);
void		raycasting3(t_game *game);
void		raycasting4(t_game *game);
void		raycasting5(t_game *game);

void		draw_ceiling_floor(t_game *game, int draw_start, int draw_end, uint32_t color);
void		draw_textures(t_game *game);

void	free_all(t_game *game);
#endif