/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dummy_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 21:50:54 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 21:06:23 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft/libft.h"
#include <stdlib.h>

void		free_dummy(t_map *map)
{
	int	y;

	y = map->max_y + 1;
	while (y > 0)
	{
		free(map->dummy[y]);
		y--;
	}
	free(map->dummy[y]);
	free(map->dummy);
	map->dummy = NULL;
}

static void	copy_line(t_pool *pool, t_map *map, char *map_str, int y)
{
	int	x;

	x = 1;
	while (x < map->max_x + 1 && map_str[map->index] != '\n' \
								&& map_str[map->index] != '\0')
	{
		if (map_str[map->index] == '\t')
			x += 3;
		else if (ft_strchr("210", map_str[map->index]))
			map->dummy[y][x] = map_str[map->index] - '0';
		else if (ft_strchr("NESW", map_str[map->index]))
		{
			map->start_pos_x = x;
			map->start_pos_y = y;
			if (!map->start_orientation)
				map->start_orientation = map_str[map->index];
			else
				exit_game("Too many starting positions declared!\n", pool);
			map->dummy[y][x] = 0;
		}
		map->index++;
		x++;
		if (map_str[map->index] == '\n')
			break ;
	}
}

void		copy_map_to_dummy(t_pool *pool, t_map *map, char *map_str)
{
	int	line;

	line = 1;
	while (line < map->max_y + 1)
	{
		copy_line(pool, map, map_str, line);
		if (map_str[map->index] == '\n')
			map->index++;
		line++;
	}
}

void		init_dummy(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->max_y + 2)
	{
		x = 0;
		while (x < map->max_x + 2)
		{
			map->dummy[y][x] = 9;
			x++;
		}
		y++;
	}
}
