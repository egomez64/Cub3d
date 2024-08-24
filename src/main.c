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
	mlx_image_t	*img;

	mlx = mlx_init(1024, 512, "Cub3d", true);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, 1024, 512);
	if (!img || (mlx_image_to_window(mlx, img, 1024, 512) < 0))
		return (1);
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
