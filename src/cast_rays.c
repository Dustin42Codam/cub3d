/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_rays.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 14:20:53 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/05 00:38:55 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

static void	calc_step_distance(t_pool *pool)
{
	if (pool->data->ray_x < 0)
	{
		pool->data->step_x = -1;
		pool->data->distance_x = (pool->data->position_x - pool->data->map_x)\
							* pool->data->delta_x;
	}
	else
	{
		pool->data->step_x = 1;
		pool->data->distance_x = (pool->data->map_x + 1.0 \
							- pool->data->position_x) * pool->data->delta_x;
	}
	if (pool->data->ray_y < 0)
	{
		pool->data->step_y = -1;
		pool->data->distance_y = (pool->data->position_y - pool->data->map_y)\
							* pool->data->delta_y;
	}
	else
	{
		pool->data->step_y = 1;
		pool->data->distance_y = (pool->data->map_y + 1.0 \
							- pool->data->position_y) * pool->data->delta_y;
	}
}

static void	make_steps(t_pool *pool)
{
	if (pool->data->distance_x < pool->data->distance_y)
	{
		pool->data->distance_x += pool->data->delta_x;
		pool->data->map_x += pool->data->step_x;
		pool->data->side = 0;
	}
	else
	{
		pool->data->distance_y += pool->data->delta_y;
		pool->data->map_y += pool->data->step_y;
		pool->data->side = 1;
	}
	if (pool->map->area[pool->data->map_y][pool->data->map_x] == 1)
		pool->data->hit = 1;
}

static void	dda_algorithm(t_pool *pool)
{
	pool->data->cam_x = 2 * pool->data->x / (double)pool->map->res_x - 1;
	pool->data->ray_x = pool->data->direction_x + (pool->data->plane_x \
						* pool->data->cam_x);
	pool->data->ray_y = pool->data->direction_y + (pool->data->plane_y \
						* pool->data->cam_x);
	pool->data->delta_x = fabs(1 / pool->data->ray_x);
	pool->data->delta_y = fabs(1 / pool->data->ray_y);
	pool->data->map_x = (int)pool->data->position_x;
	pool->data->map_y = (int)pool->data->position_y;
	calc_step_distance(pool);
	pool->data->hit = 0;
	while (!pool->data->hit)
		make_steps(pool);
}

void		cast_rays(t_pool *pool)
{
	while (pool->data->x < pool->map->res_x)
	{
		dda_algorithm(pool);
		calculate_walls(pool);
		draw_ray_to_image(pool);
		pool->data->x++;
	}
}
