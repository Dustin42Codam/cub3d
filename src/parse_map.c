/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 20:26:30 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft/libft.h"

void		free_map_area(t_map *map)
{
	int	y;

	y = map->max_y - 1;
	while (y > 0)
	{
		free(map->area[y]);
		y--;
	}
	free(map->area[y]);
	free(map->area);
}

static void	malloc_map_area(t_pool *pool, t_map *map)
{
	int	y;

	y = 0;
	map->area = (int**)malloc(sizeof(int*) * map->max_x * map->max_y);
	if (map->area == NULL)
		exit_game("Memory allocation failed! [parse_map.c]\n", pool);
	while (y < map->max_y)
	{
		map->area[y] = (int*)malloc(sizeof(int) * map->max_x);
		if (map->area[y] == NULL)
			exit_game("Memory allocation failed! [parse_map.c]\n", pool);
		y++;
	}
}

static void	copy_valid_dummy_to_map(t_map *map)
{
	int	dx;
	int	dy;
	int	gx;
	int	gy;

	dx = 1;
	dy = 1;
	gx = 0;
	gy = 0;
	while (gy < map->max_y)
	{
		gx = 0;
		dx = 1;
		while (gx < map->max_x)
		{
			if (map->dummy[dy][dx] != OUT_OF_MAP)
				map->area[gy][gx] = map->dummy[dy][dx];
			else
				map->area[gy][gx] = OUT_OF_MAP;
			gx++;
			dx++;
		}
		dy++;
		gy++;
	}
}

static void	get_max_axes(t_map *map, char *map_str)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = map->index;
	while (map_str[i] != '\0')
	{
		while (map_str[i] == '\n')
		{
			i++;
			map->max_y++;
		}
		map->max_x = tmp > map->max_x ? tmp : map->max_x;
		tmp = 0;
		while (map_str[i] != '\n' && map_str[i] != '\0')
		{
			tmp++;
			i++;
			if (map_str[i] == '\n' || map_str[i] == '\0')
				map->max_y++;
		}
		if (map_str[i] != '\0')
			i++;
	}
}

void		parse_map(t_pool *pool, t_map *map, char *map_str)
{
	int	map_line;

	map_line = 0;
	while (map_str[map->index - 1] != '\n')
		map->index--;
	get_max_axes(map, map_str);
	map->dummy = (int**)malloc(sizeof(int*) * \
					(map->max_x + 2) * (map->max_y + 2));
	if (map->dummy == NULL)
		exit_game("Memory allocation failed! [parse_map.c]\n", pool);
	while (map_line < map->max_y + 2)
	{
		map->dummy[map_line] = (int*)malloc(sizeof(int) * \
								map->max_x + (2 * sizeof(int)));
		if (map->dummy[map_line] == NULL)
			exit_game("Memory allocation failed! [parse_map.c]\n", pool);
		map_line++;
	}
	init_dummy(map);
	copy_map_to_dummy(pool, map, map_str);
	validate_dummy_map(pool, map);
	malloc_map_area(pool, map);
	copy_valid_dummy_to_map(map);
	free_dummy(map);
	ft_putstr_fd("\033[1;32mMap content:\t [SUCCESS]\033[0m\n", 1);
}
