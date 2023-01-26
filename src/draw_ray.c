/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_ray.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 09:36:46 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/05 01:02:22 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_texture_rgb(t_pool *pool, int orientation)
{
	int	rgb;

	pool->img->texture_y = (int)pool->img->texture_pos;
	pool->img->texture_pos = pool->img->texture_pos + pool->img->step;
	if (orientation == 'S')
		rgb = *(int*)(pool->texture->address_south + (pool->img->texture_y * \
		pool->texture->ls_south + pool->img->texture_x * \
		(pool->texture->bpp_south / 8)));
	else if (orientation == 'N')
		rgb = *(int*)(pool->texture->address_north + (pool->img->texture_y * \
		pool->texture->ls_north) + (pool->img->texture_x * \
		(pool->texture->bpp_north / 8)));
	else if (orientation == 'W')
		rgb = *(int*)(pool->texture->address_west + (pool->img->texture_y * \
		pool->texture->ls_west + pool->img->texture_x * \
		(pool->texture->bpp_west / 8)));
	else
		rgb = *(int*)(pool->texture->address_east + (pool->img->texture_y * \
		pool->texture->ls_east + pool->img->texture_x * \
		(pool->texture->bpp_east / 8)));
	return (rgb);
}

void		draw_ray_to_image(t_pool *pool)
{
	int	y;

	y = pool->img->line_end;
	while (pool->img->line_start < pool->img->line_end)
	{
		*(int*)(pool->mlx->address + (pool->img->line_start * \
		pool->mlx->size_line) + (pool->data->x * \
		(pool->mlx->bits_per_pixel / 8))) = \
		get_texture_rgb(pool, pool->data->wall_orientation);
		pool->img->line_start++;
	}
	while (y < pool->img->wall_height - 1)
	{
		*(int*)(pool->mlx->address + (y * pool->mlx->size_line) + \
		(pool->data->x * (pool->mlx->bits_per_pixel / 8))) = pool->map->floor;
		*(int*)(pool->mlx->address + ((pool->img->wall_height - y - 1) * \
		pool->mlx->size_line) + (pool->data->x * \
		(pool->mlx->bits_per_pixel / 8))) = pool->map->ceiling;
		y++;
	}
}
