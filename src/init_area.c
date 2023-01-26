/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_area.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 08:13:11 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_area(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->area[y][x] = 9;
			x++;
		}
		y++;
	}
}
