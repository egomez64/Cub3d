/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/20 17:06:29 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**cpy_tab(t_game *data)
{
	int	i;
	char **map;

	i = 0;
	map = ft_calloc(1, sizeof(char *) * (data->map.line - data->map.start_map));
	while (data->map.map[i])
	{
		map[i] = ft_strdup(data->map.map[i]);
		i++;
	}
	return (map);
}

int	check_line(char *str, t_game *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			data->texture.direction += 1;
		if (!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}


static int	validate_line(char *line, t_game *data)
{
	if (line[0] != '1' && line[0] != ' ')
		exit_error("error: invalid map1\n");
	if (check_line(line, data) == 1)
		exit_error("error: invalid map2\n");
	return (0);
}

static int	flood_fill(char **map, int x, int y, t_game *game)
{
	int len;

	len = game->map.line;
	map[y][x] = '1';
	if (y > 0 && x < strlen_flood(map[y - 1]) && \
	map[y - 1][x] == '0')
		flood_fill(map, x, y - 1, game);
	else if (y == 0 || (y > 0 && x < strlen_flood(map[y - 1]) && \
	map[y - 1][x] != '1') || (y > 0 && x >= strlen_flood(map[y - 1])))
		return (1);
	if (x > 0 && y < len && map[y][x - 1] == '0')
		flood_fill(map, x - 1, y, game);
	else if (x == 0 ||(x > 0 && y < len && map[y][x - 1] != '1'))
		return (1);
	if (y < len - 1 && x < strlen_flood(map[y + 1]) && map[y + 1][x] == '0')
		flood_fill(map, x, y + 1, game);
	else if (y == len - 1 || (y < len - 1 && \
	x < strlen_flood(map[y + 1]) && map[y + 1][x] != '1') ||
	(y < len - 1 && x >= strlen_flood(map[y + 1])))
		return (1);
	if (x < strlen_flood(map[y]) - 1 && y < len && map[y][x + 1] == '0')
		flood_fill(map, x + 1, y, game);
	else if (x == strlen_flood(map[y]) - 1 || (x < strlen_flood(map[y]) - 1 && \
	y < len && map[y][x + 1] != '1'))
		return (1);
	return (0);
}

static char	**no_space_arround_player(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = cpy_tab(game);
	x = game->player.x;
	y = game->player.y;
	if (flood_fill(map, x, y, game) == 1)
	{
		ft_putstr_fd("error: invalid map5\n", 2);
		free_tab(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
void is_empty_line(char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		exit_error("error: empty line on map");
}
void while_empty_line(char ***map)
{
	while (**map && ***map == '\0')
		(*map)++;
}

int	check_map(t_game *data)
{
	int i;
	char **map;
	char **map_cpy;

	i = 0;

	map = data->map.map;
	while (map[i])
	{
		is_empty_line(map[i]);
		validate_line(map[i], data);

		i++;
	}
	get_pos_player(data);
	if (data->texture.direction != 1)
		exit_error("error: invalid map3\n");
	map_cpy = no_space_arround_player(data);
	check_zero(data,map_cpy);
	return (0);
}
void parse_map(t_game *data)
{
		while_empty_line(&data->map.map);
		check_map(data);
}