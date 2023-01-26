/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 20:29:08 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 17:48:08 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>
#include "libft/libft.h"

static void	validate_data(t_pool *pool, t_map *map)
{
	if (map->res_x == 0 || map->res_y == 0)
		exit_game("Invalid resolution!\n", pool);
	else if (!map->texture_north || !map->texture_south
		|| !map->texture_east || !map->texture_west)
		exit_game("Invalid wall texture!\n", pool);
	else if (!map->texture_sprite)
		exit_game("Invalid sprite texture!\n", pool);
	else if (map->max_x == 0 || map->max_y == 0)
		exit_game("Invalid map structure!\n", pool);
	else if (map->start_pos_x == 0 || map->start_pos_y == 0)
		exit_game("Invalid starting position!\n", pool);
	else if (!map->start_orientation)
		exit_game("Invalid starting orientation!\n", pool);
	else if (!map->area)
		exit_game("Invalid map data!\n", pool);
	else if (map->floor == -1)
		exit_game("Invalid floor color!\n", pool);
	else if (map->ceiling == -1)
		exit_game("Invalid ceiling color!\n", pool);
}

static void	check_string_content(t_pool *pool, t_map *map, char *map_str)
{
	if (map_str[map->index] == 'R')
		parse_resolution(pool, map, map_str);
	else if (map_str[map->index] == 'N' && map_str[map->index + 1] == 'O')
		parse_textures(pool, map_str, NORTH);
	else if (map_str[map->index] == 'S' && map_str[map->index + 1] == 'O')
		parse_textures(pool, map_str, SOUTH);
	else if (map_str[map->index] == 'W' && map_str[map->index + 1] == 'E')
		parse_textures(pool, map_str, WEST);
	else if (map_str[map->index] == 'E' && map_str[map->index + 1] == 'A')
		parse_textures(pool, map_str, EAST);
	else if (map_str[map->index] == 'S' && map_str[map->index] != 'O')
		parse_sprite(pool, map_str, SPRITE);
	else if (map_str[map->index] == 'F')
		parse_rgb(pool, map, FLOOR);
	else if (map_str[map->index] == 'C')
		parse_rgb(pool, map, CEILING);
	else if (map->res_x && map->res_y && map->texture_west && \
			map->texture_north && map->texture_south && \
			map->texture_east && map->texture_sprite && \
			map->parse_check && \
			(map_str[map->index] == ' ' || map_str[map->index] == '1'))
		parse_map(pool, map, map_str);
	else if (map_str[map->index] != '\n')
		exit_game("Invalid data in .cub file provided!\n", pool);
}

static void	parse_map_string(t_pool *pool, t_map *map, char *map_string)
{
	while (map_string[map->index] != '\0' && !map->area)
	{
		while (ft_isspace(map_string[map->index]))
			map->index++;
		check_string_content(pool, map, map_string);
	}
	validate_data(pool, map);
}

void		parser(t_pool *pool, t_map *map, char *file)
{
	char	*map_string;
	int		fd;

	map_string = NULL;
	map->main_ptr = &map_string;
	ft_putstr_fd("\033[1;34mChecking file content...\n\033[0m", 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_game("Failed to open file! [src/parser.c]\n", pool);
	map_string = ft_calloc(1, sizeof(char));
	if (map_string == NULL)
		exit_game("Memory allocation failed!  [src/parser.c]\n", pool);
	map_string = read_map(pool, map_string, fd);
	parse_map_string(pool, map, map_string);
	free(map_string);
	map->main_ptr = NULL;
	set_orientation(pool, map);
	set_sprites(pool, map, pool->sprite);
	pool->map->parse_check = 42;
	ft_putstr_fd("\033[1;32mData status:\t[VALIDATED]\033[0m\n", 1);
}
