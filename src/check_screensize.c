/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_screensize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 13:15:56 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 00:58:35 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"

void	check_screensize(t_pool *pool)
{
	int	screen_size_x;
	int	screen_size_y;

	mlx_get_screen_size(pool->mlx->ptr, &screen_size_x, &screen_size_y);
	if (screen_size_x <= 0 || screen_size_y <= 0)
		exit_game("MLX failed to load screensize!\n", pool);
	if (pool->map->res_x > screen_size_x)
		pool->map->res_x = screen_size_x;
	if (pool->map->res_y > screen_size_y)
		pool->map->res_y = screen_size_y;
}
