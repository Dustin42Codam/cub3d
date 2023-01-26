/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_hooks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 07:54:15 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 16:13:52 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"

static void	trigger_hooks(t_pool *pool)
{
	if (pool->data->forward)
		player_move_forward(pool->data, pool->map);
	if (pool->data->backward)
		player_move_backward(pool->data, pool->map);
	if (pool->data->left)
		player_move_left(pool->data, pool->map);
	if (pool->data->right)
		player_move_right(pool->data, pool->map);
	if (pool->data->rotate_left)
		player_rotate_left(pool->data);
	if (pool->data->rotate_right)
		player_rotate_right(pool->data);
}

static void	get_render_status(t_pool *pool)
{
	if (pool->data->forward)
		pool->mlx->render_status = 1;
	if (pool->data->backward)
		pool->mlx->render_status = 1;
	if (pool->data->left)
		pool->mlx->render_status = 1;
	if (pool->data->right)
		pool->mlx->render_status = 1;
	if (pool->data->rotate_left)
		pool->mlx->render_status = 1;
	if (pool->data->rotate_right)
		pool->mlx->render_status = 1;
}

static void	swap_image(t_mlx *mlx)
{
	mlx->old_image = mlx->new_image;
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->old_image, 0, 0);
}

void		create_new_image(t_pool *pool, t_mlx *mlx, t_map *map)
{
	mlx->new_image = mlx_new_image(mlx->ptr, map->res_x, map->res_y);
	if (mlx->new_image == NULL)
		exit_game("MLX failed to create an image!\n", pool);
	mlx->address = mlx_get_data_addr(mlx->new_image, &mlx->bits_per_pixel, \
									&mlx->size_line, &mlx->endian);
}

int			loop_hooks(t_pool *pool)
{
	get_render_status(pool);
	if (pool->mlx->render_status == 0)
		return (0);
	trigger_hooks(pool);
	if (pool->mlx->new_image)
		swap_image(pool->mlx);
	create_new_image(pool, pool->mlx, pool->map);
	cast_rays(pool);
	if (pool->sprite->number)
		cast_sprites(pool);
	mlx_put_image_to_window(pool->mlx->ptr, pool->mlx->window, \
							pool->mlx->new_image, 0, 0);
	if (pool->mlx->old_image)
	{
		mlx_destroy_image(pool->mlx->ptr, pool->mlx->old_image);
		pool->mlx->old_image = NULL;
	}
	pool->data->x = 0;
	pool->mlx->render_status = 0;
	return (0);
}
