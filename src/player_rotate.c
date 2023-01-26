/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 10:08:23 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	player_rotate_right(t_data *data)
{
	data->direction_x_old = data->direction_x;
	data->plane_x_old = data->plane_x;
	data->direction_x = data->direction_x * cos(0.042) - \
	data->direction_y * sin(0.042);
	data->plane_x = data->plane_x * cos(0.042) - data->plane_y * sin(0.042);
	data->direction_y = data->direction_x_old * sin(0.042) + \
	data->direction_y * cos(0.042);
	data->plane_y = data->plane_x_old * sin(0.042) + data->plane_y * \
	cos(0.042);
}

void	player_rotate_left(t_data *data)
{
	data->direction_x_old = data->direction_x;
	data->plane_x_old = data->plane_x;
	data->direction_x = data->direction_x * cos(-0.042) - \
	data->direction_y * sin(-0.042);
	data->plane_x = data->plane_x * cos(-0.042) - data->plane_y * sin(-0.042);
	data->direction_y = data->direction_x_old * sin(-0.042) + \
	data->direction_y * cos(-0.042);
	data->plane_y = data->plane_x_old * sin(-0.042) + data->plane_y * \
	cos(-0.042);
}
