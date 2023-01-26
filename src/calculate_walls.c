/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_walls.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 07:49:55 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/04 23:06:55 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

static void	get_tex_pos_x(t_img *img, t_texture *tex, t_data *data)
{
	if (data->wall_orientation == 'N')
	{
		img->texture_x = (int)(data->wall_x * (double)tex->x_north);
		return ;
	}
	if (data->wall_orientation == 'S')
	{
		img->texture_x = (int)(data->wall_x * (double)tex->x_south);
		return ;
	}
	if (data->wall_orientation == 'W')
	{
		img->texture_x = (int)(data->wall_x * (double)tex->x_west);
		return ;
	}
	if (data->wall_orientation == 'E')
		img->texture_x = (int)(data->wall_x * (double)tex->x_east);
}

static void	get_tex_pos_y(t_img *img, t_texture *tex, t_data *data)
{
	if (data->wall_orientation == 'S')
		img->step = 1.0 * tex->y_south / img->line_y;
	else if (data->wall_orientation == 'N')
		img->step = 1.0 * tex->y_north / img->line_y;
	else if (data->wall_orientation == 'W')
		img->step = 1.0 * tex->y_west / img->line_y;
	else if (data->wall_orientation == 'E')
		img->step = 1.0 * tex->y_east / img->line_y;
	img->texture_pos = (img->line_start - (img->wall_height / 2) + \
	(img->line_y / 2)) * img->step;
}

static void	get_distance_to_wall(t_data *data)
{
	if (data->side == 0)
	{
		data->wall_distance[data->x] = (data->map_x - data->position_x + \
		(1.0 - data->step_x) / 2) / data->ray_x;
		data->wall_x = data->position_y + data->wall_distance[data->x] * \
						data->ray_y;
		data->wall_orientation = (data->ray_x < 0) ? 'W' : 'E';
	}
	else
	{
		data->wall_distance[data->x] = (data->map_y - data->position_y + \
									(1.0 - data->step_y) / 2) / data->ray_y;
		data->wall_x = data->position_x + data->wall_distance[data->x] * \
						data->ray_x;
		data->wall_orientation = (data->ray_y < 0) ? 'N' : 'S';
	}
	data->wall_x = data->wall_x - floor(data->wall_x);
}

static void	get_wall_height(t_map *map, t_data *data, t_img *img)
{
	img->wall_height = map->res_y;
	img->line_y = 1 * ((int)(img->wall_height / data->wall_distance\
	[data->x]));
	img->line_start = -(img->line_y / 2) + (img->wall_height / 2);
	if (img->line_start < 0)
		img->line_start = 0;
	img->line_end = (img->line_y / 2) + (img->wall_height / 2);
	if (img->line_end >= img->wall_height)
		img->line_end = img->wall_height - 1;
}

void		calculate_walls(t_pool *pool)
{
	get_distance_to_wall(pool->data);
	get_wall_height(pool->map, pool->data, pool->img);
	get_tex_pos_x(pool->img, pool->texture, pool->data);
	get_tex_pos_y(pool->img, pool->texture, pool->data);
}
