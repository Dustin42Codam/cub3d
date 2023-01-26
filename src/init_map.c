/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 03:04:23 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_map_tail(t_map *map)
{
	map->area = NULL;
	map->dummy = NULL;
	map->start_orientation = 0;
	map->check = 0;
	map->screenshot = 0;
	map->parse_check = 0;
	map->main_ptr = NULL;
	map->path_ptr = NULL;
}

void		init_map(t_map *map)
{
	map->index = 0;
	map->res_x = 0;
	map->res_y = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->texture_north = NULL;
	map->texture_west = NULL;
	map->texture_east = NULL;
	map->texture_south = NULL;
	map->texture_sprite = NULL;
	map->start_pos_x = 0;
	map->start_pos_y = 0;
	map->floor = -1;
	map->floor_r = 0;
	map->floor_g = 0;
	map->floor_b = 0;
	map->ceiling = -1;
	map->ceiling_r = 0;
	map->ceiling_g = 0;
	map->ceiling_b = 0;
	map->rgb_count = 0;
	map->rgb_comma = 0;
	init_map_tail(map);
}
