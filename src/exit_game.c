/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 18:33:48 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 19:45:34 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <unistd.h>
#include "libft/libft.h"
#include "../mlx/mlx.h"

static void	free_everything(t_pool *pool)
{
	if (pool->map->dummy != NULL)
		free_dummy(pool->map);
	if (pool->map->area != NULL)
		free_map_area(pool->map);
	if (pool->map->main_ptr != NULL)
		free((*pool->map->main_ptr));
	if (pool->map->texture_north != NULL)
		free(pool->map->texture_north);
	if (pool->map->texture_east != NULL)
		free(pool->map->texture_east);
	if (pool->map->texture_south != NULL)
		free(pool->map->texture_south);
	if (pool->map->texture_west != NULL)
		free(pool->map->texture_west);
	if (pool->map->texture_sprite != NULL)
		free(pool->map->texture_sprite);
	if (pool->data->wall_distance != NULL)
		free(pool->data->wall_distance);
	if (pool->sprite->entity != NULL)
		free_sprites(pool->sprite);
	if (pool->sprite->distance != NULL)
		free(pool->sprite->distance);
}

void		exit_game(char *msg, t_pool *pool)
{
	if (pool->map->screenshot == 0 && ft_strncmp(msg, "Closing game!\n", 14))
		ft_putstr_fd("\033[1;31mError\n\033[0m", 1);
	ft_putstr_fd(msg, 1);
	if (pool->map->parse_check == 42)
	{
		if (pool->mlx->window != NULL)
			mlx_destroy_window(pool->mlx->ptr, pool->mlx->window);
		if (pool->mlx->old_image != NULL)
			mlx_destroy_image(pool->mlx->ptr, pool->mlx->old_image);
		if (pool->mlx->new_image != NULL)
			mlx_destroy_image(pool->mlx->ptr, pool->mlx->new_image);
		if (pool->mlx->ptr != NULL)
			free(pool->mlx->ptr);
	}
	free_everything(pool);
	ft_putstr_fd("\033[1;31mExiting program!\033[0m\n", 1);
	exit(0);
}
