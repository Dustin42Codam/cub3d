/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_sprites.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 23:10:35 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 21:06:23 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft/libft.h"
#include <stdlib.h>

void		free_sprites(t_sprite *sprite)
{
	int	index;

	index = sprite->number - 1;
	while (index >= 0)
	{
		free(sprite->entity[index]);
		index--;
	}
	free(sprite->entity);
}

static void	count_sprites(t_map *map, t_sprite *sprite)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->max_y - 1)
	{
		x = 1;
		while (x < map->max_x - 1)
		{
			if (map->area[y][x] == 2)
				sprite->number++;
			x++;
		}
		y++;
	}
}

static void	malloc_sprites(t_pool *pool, t_sprite *sprite)
{
	int	index;

	index = 0;
	sprite->entity = (double**)malloc(sizeof(double*) * sprite->number);
	if (sprite->entity == NULL)
		exit_game("Malloc failed! [src/set_sprites.c]\n", pool);
	while (index < sprite->number)
	{
		sprite->entity[index] = (double*)malloc(sizeof(double) * 2);
		if (sprite->entity[index] == NULL)
			exit_game("Malloc failed! [src/set_sprites.c]\n", pool);
		index++;
	}
	sprite->distance = (double*)malloc(sizeof(double) * sprite->number);
	if (sprite->distance == NULL)
		exit_game("Malloc failed! [src/set_sprites.c]\n", pool);
}

static void	set_sprite_position(t_map *map, t_sprite *sprite)
{
	int		y;
	int		x;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (y < map->max_y)
	{
		while (x < map->max_x)
		{
			if (map->area[y][x] == 2)
			{
				sprite->entity[count][0] = y + 0.5;
				sprite->entity[count][1] = x + 0.5;
				count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void		set_sprites(t_pool *pool, t_map *map, t_sprite *sprite)
{
	count_sprites(map, sprite);
	malloc_sprites(pool, sprite);
	set_sprite_position(map, sprite);
}
