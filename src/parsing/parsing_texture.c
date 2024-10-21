/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:40:11 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/20 15:48:51 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_count_texture(t_game *data)
{
	if (data->texture.count_we != 1 || data->texture.count_so != 1
		|| data->texture.count_no != 1 || data->texture.count_ea != 1
		|| data->texture.count_f != 1 || data->texture.count_c != 1)
		return (1);
	return (0);
}

void	check_for_texture(char **map, t_game *data)
{
	int		i;

	i = 0;
	while(map[i])
	{
		if (!ft_strncmp(map[i], "NO ", 3))
			data->texture.count_no++;
		if (!ft_strncmp(map[i], "SO ", 3))
			data->texture.count_so++;
		if (!ft_strncmp(map[i], "EA ", 3))
			data->texture.count_ea++;
		if (!ft_strncmp(map[i], "WE ", 3))
			data->texture.count_we++;
		if (!ft_strncmp(map[i], "F ", 2))
			data->texture.count_f++;
		if (!ft_strncmp(map[i], "C ", 2))
			data->texture.count_c++;
		i++;
	}
	if(check_count_texture(data) == 1)
		exit_error("error: not enought textures !\n");
}

static void	load_image(char *line, mlx_texture_t **path, int *count)
{
	char	**tab;
	*path = NULL;
	tab = ft_split(line, ' ');
	
	if (!tab || !line)
	{
		free(tab);
		free(line);
		exit_error("error: texture can't be load1\n");
	}
	*path = mlx_load_png(tab[1]);
	if (!(*path))
	{
		free_tab(tab);
		free(line);
		exit_error("error: texture can't be load\n");
	}
	(*count)++;
	// free(line);
	free_tab(tab);
}

static void	load_texture(char **map, t_game *data, int i, int *count)
{
	if (strncmp(map[i], "NO ", 3) == 0)
		load_image(map[i], &data->texture.path[0], count);
	else if (strncmp(map[i], "SO ", 3) == 0)
		load_image(map[i], &data->texture.path[1], count);
	else if (strncmp(map[i], "EA ", 3) == 0)
		load_image(map[i], &data->texture.path[2], count);
	else if (strncmp(map[i], "WE ", 3) == 0)
		load_image(map[i], &data->texture.path[3], count);
	else if (strncmp(map[i], "F ", 2) == 0)
		set_color(data, map[i], count);
	else if (strncmp(map[i], "C ", 2) == 0)
		set_color(data, map[i], count);
}

void	check_texture(char **map, t_game *data)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		load_texture(map, data, i, &count);
		if (strncmp(map[i], "NO ", 3) && strncmp(map[i], "SO ", 3) && strncmp(map[i], "EA ", 3)
			&& strncmp(map[i], "WE ", 3) && strncmp(map[i], "F ", 2) && strncmp(map[i], "C ", 2) && map[i][0] != '\0')
			exit_error("error: try to load a bad name texture !\n");
		if(count == 6)
			break ;
		i++;
	}
	data->map.start_map = i + 1;
}
