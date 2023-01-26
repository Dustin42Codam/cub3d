/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_dummy_map.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 08:16:43 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	visit_neighbours(t_pool *pool, t_map *map, int x, int y)
{
	if (map->dummy[y - 1][x - 1] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (map->dummy[y - 1][x] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (x != map->max_x && map->dummy[y - 1][x + 1] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (map->dummy[y][x - 1] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (map->dummy[y][x + 1] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (map->dummy[y + 1][x - 1] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (map->dummy[y + 1][x] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
	if (map->dummy[y + 1][x + 1] == OUT_OF_MAP)
		exit_game("Invalid map data provided!\n", pool);
}

void		validate_dummy_map(t_pool *pool, t_map *map)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->max_y + 1)
	{
		x = 1;
		while (x < map->max_x + 1)
		{
			if (map->dummy[y][x] == 0 || map->dummy[y][x] == 2)
				visit_neighbours(pool, map, x, y);
			x++;
		}
		y++;
	}
}
