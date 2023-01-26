/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_orientation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 03:11:39 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>

void	set_orientation(t_pool *pool, t_map *map)
{
	pool->data->position_x = (double)map->start_pos_x - 0.5;
	pool->data->position_y = (double)map->start_pos_y - 0.5;
	pool->data->wall_distance = (double*)malloc(sizeof(double) * map->res_x);
	if (pool->data->wall_distance == NULL)
		exit_game("Malloc failed! [set_orientation.c]\n", pool);
	if (map->start_orientation == 'N')
	{
		pool->data->direction_y = -1;
		pool->data->plane_x = 0.66;
	}
	else if (map->start_orientation == 'E')
	{
		pool->data->direction_x = 1;
		pool->data->plane_y = 0.66;
	}
	else if (map->start_orientation == 'S')
	{
		pool->data->direction_y = 1;
		pool->data->plane_x = -0.66;
	}
	else if (map->start_orientation == 'W')
	{
		pool->data->direction_x = -1;
		pool->data->plane_y = -0.66;
	}
}
