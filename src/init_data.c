/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 03:04:23 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>

static void	init_data_tail(t_data *data)
{
	data->backward = 0;
	data->forward = 0;
	data->right = 0;
	data->left = 0;
	data->rotate_right = 0;
	data->rotate_left = 0;
	data->side = 0;
	data->x = 0;
	data->wall_x = 0;
	data->wall_orientation = '0';
}

void		init_data(t_data *data)
{
	data->position_x = 0;
	data->position_y = 0;
	data->direction_x = 0;
	data->direction_x_old = 0;
	data->direction_y = 0;
	data->plane_x = 0;
	data->plane_x_old = 0;
	data->plane_y = 0;
	data->delta_x = 0;
	data->delta_y = 0;
	data->wall_distance = NULL;
	data->ray_x = 0;
	data->ray_y = 0;
	data->distance_y = 0;
	data->distance_x = 0;
	data->map_y = 0;
	data->map_x = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->hit = 0;
	data->cam_x = 0;
	init_data_tail(data);
}
