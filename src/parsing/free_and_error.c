/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:31:23 by bdany             #+#    #+#             */
/*   Updated: 2024/10/17 18:29:51 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}


void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}


// void	free_all(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	if (game->map.img)
// 		mlx_delete_image(game->map.mlx, game->map.img);
// 	if (game->map.mlx)
// 		mlx_close_window(game->map.mlx);
// 	if (game->map.map)
// 	{
// 		while (game->map.map[i])
// 		{
// 			free(game->map.map[i]);
// 			i++;
// 		}
// 		free(game->map.map);
// 	}
// }

void	exit_error(char *str)
{
	// t_game *game;
	
	ft_putstr_fd(str, 2);
	// free_tab(game);
	// free_all(game);
	exit(EXIT_FAILURE);
}


