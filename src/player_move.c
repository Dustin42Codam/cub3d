/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 08:53:05 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 01:00:59 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_move_forward(t_data *data, t_map *map)
{
	if (map->area[(int)data->position_y][(int)(data->position_x + \
		(data->direction_x * 0.15))] == 0)
		data->position_x = data->position_x + (data->direction_x * 0.1);
	if (map->area[(int)(data->position_y + (data->direction_y * \
		0.15))][(int)data->position_x] == 0)
		data->position_y = data->position_y + (data->direction_y * 0.1);
}

void	player_move_backward(t_data *data, t_map *map)
{
	if (map->area[(int)data->position_y][(int)(data->position_x - \
		(data->direction_x * 0.15))] == 0)
		data->position_x = data->position_x - (data->direction_x * 0.1);
	if (map->area[(int)(data->position_y - (data->direction_y * \
		0.15))][(int)data->position_x] == 0)
		data->position_y = data->position_y - (data->direction_y * 0.1);
}

void	player_move_right(t_data *data, t_map *map)
{
	if (map->area[(int)data->position_y][(int)(data->position_x + \
		(data->plane_x * 0.15))] == 0)
		data->position_x = data->position_x + (data->plane_x * 0.1);
	if (map->area[(int)(data->position_y + (data->plane_y * \
		0.15))][(int)data->position_x] == 0)
		data->position_y = data->position_y + (data->plane_y * 0.1);
}

void	player_move_left(t_data *data, t_map *map)
{
	if (map->area[(int)data->position_y][(int)(data->position_x - \
		(data->plane_x * 0.15))] == 0)
		data->position_x = data->position_x - (data->plane_x * 0.1);
	if (map->area[(int)(data->position_y - (data->plane_y * 0.15))]\
				[(int)data->position_x] == 0)
		data->position_y = data->position_y - (data->plane_y * 0.1);
}
