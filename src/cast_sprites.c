/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 14:47:47 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/04 23:53:26 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>

static void	sort_sprite_distance(t_sprite *sprite)
{
	double	y_swap;
	double	x_swap;
	double	distance_swap;
	int		i;

	i = 0;
	while (i < (sprite->number - 1))
	{
		if (sprite->distance[i] < sprite->distance[i + 1])
		{
			y_swap = sprite->entity[i + 1][0];
			x_swap = sprite->entity[i + 1][1];
			distance_swap = sprite->distance[i + 1];
			sprite->distance[i + 1] = sprite->distance[i];
			sprite->entity[i + 1][0] = sprite->entity[i][0];
			sprite->entity[i + 1][1] = sprite->entity[i][1];
			sprite->distance[i] = distance_swap;
			sprite->entity[i][0] = y_swap;
			sprite->entity[i][1] = x_swap;
			i = 0;
		}
		else
			i++;
	}
}

static void	sprite_calculation(t_sprite *spr, t_data *data, t_map *map, int i)
{
	spr->position_x = spr->entity[i][1] - data->position_x;
	spr->position_y = spr->entity[i][0] - data->position_y;
	spr->inv = 1.0 / ((data->plane_x * data->direction_y) - \
					(data->plane_y * data->direction_x));
	spr->transform_x = spr->inv * ((data->direction_y * spr->position_x) \
	- (data->direction_x * spr->position_y));
	spr->transform_y = spr->inv * ((-data->plane_y * spr->position_x) \
	+ (data->plane_x * spr->position_y));
	spr->screen_x = (int)((map->res_x / 2) * (1 + spr->transform_x \
	/ spr->transform_y));
	spr->height = abs((int)(1 * (map->res_y / spr->transform_y)));
	spr->width = abs((int)(1 * (map->res_y / spr->transform_y)));
	spr->start_y = -spr->height / 2 + map->res_y / 2;
	spr->start_y = (spr->start_y < 0) ? 0 : spr->start_y;
	spr->end_y = spr->height / 2 + map->res_y / 2;
	spr->end_y = (spr->end_y >= map->res_y) ? map->res_y - 1 : spr->end_y;
	spr->start_x = -spr->width / 2 + spr->screen_x;
	spr->start_x = (spr->start_x < 0) ? 0 : spr->start_x;
	spr->end_x = spr->width / 2 + spr->screen_x;
	spr->end_x = (spr->end_x >= map->res_x) ? map->res_x - 1 : spr->end_x;
}

static void	draw_sprite_pixel(t_pool *pool, int y)
{
	int	draw_range;
	int	color;

	draw_range = (y << 8) - (pool->map->res_y << 7) + \
			(pool->sprite->height << 7);
	pool->sprite->texture_y = (draw_range * pool->texture->y_sprite) \
								/ pool->sprite->height >> 8;
	color = *(int*)(pool->texture->address_sprite + \
			(pool->sprite->texture_y * pool->texture->ls_sprite + \
			pool->sprite->texture_x * (pool->texture->bpp_sprite >> 3)));
	if (color > 0)
	{
		*(int*)(pool->mlx->address + (y * pool->mlx->size_line) + \
		(pool->sprite->stripe * (pool->mlx->bits_per_pixel >> 3))) = color;
	}
}

static void	draw_sprite(t_pool *pool)
{
	int	y;

	pool->sprite->stripe = pool->sprite->start_x;
	while (pool->sprite->stripe < pool->sprite->end_x)
	{
		pool->sprite->texture_x = (int)(256 * (pool->sprite->stripe - \
		(-pool->sprite->width / 2 + pool->sprite->screen_x)) * \
		pool->texture->x_sprite / pool->sprite->width) >> 8;
		y = pool->sprite->start_y;
		if (pool->sprite->transform_y > 0 && pool->sprite->stripe > 0 && \
		pool->sprite->stripe < pool->map->res_x && pool->sprite->transform_y < \
		pool->data->wall_distance[pool->sprite->stripe])
		{
			while (y < pool->sprite->end_y)
			{
				draw_sprite_pixel(pool, y);
				y++;
			}
		}
		pool->sprite->stripe++;
	}
}

void		cast_sprites(t_pool *pool)
{
	int	i;

	i = 0;
	while (i < pool->sprite->number)
	{
		pool->sprite->distance[i] = \
		((pool->data->position_x - pool->sprite->entity[i][1]) * \
		(pool->data->position_x - pool->sprite->entity[i][1]) + \
		(pool->data->position_y - pool->sprite->entity[i][0]) * \
		(pool->data->position_y - pool->sprite->entity[i][0]));
		i++;
	}
	sort_sprite_distance(pool->sprite);
	i = 0;
	while (i < pool->sprite->number)
	{
		sprite_calculation(pool->sprite, pool->data, pool->map, i);
		draw_sprite(pool);
		i++;
	}
}
