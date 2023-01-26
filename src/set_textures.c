/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_textures.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 12:07:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 00:00:08 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

static void	set_texture_north(t_pool *pool)
{
	size_t	search_offset;

	search_offset = ft_strlen(pool->map->texture_north) - 4;
	if (ft_strnstr(pool->map->texture_north + search_offset, ".xpm", 4))
		pool->texture->north = mlx_xpm_file_to_image(pool->mlx->ptr, \
		pool->map->texture_north, &pool->texture->x_north, \
		&pool->texture->y_north);
	else if (ft_strnstr(pool->map->texture_north + search_offset, ".png", 4))
		pool->texture->north = mlx_png_file_to_image(pool->mlx->ptr, \
		pool->map->texture_north, &pool->texture->x_north, \
		&pool->texture->y_north);
	free(pool->map->texture_north);
	pool->map->texture_north = NULL;
	pool->texture->address_north = mlx_get_data_addr(pool->texture->north, \
	&pool->texture->bpp_north, &pool->texture->ls_north, \
	&pool->texture->endian_north);
	if (!pool->texture->north || !pool->texture->address_north)
		exit_game("MLX failed to process texture 'NO'!\n", pool);
}

static void	set_texture_south(t_pool *pool)
{
	size_t	search_offset;

	search_offset = ft_strlen(pool->map->texture_south) - 4;
	if (ft_strnstr(pool->map->texture_south + search_offset, ".xpm", 4))
		pool->texture->south = mlx_xpm_file_to_image(pool->mlx->ptr, \
		pool->map->texture_south, &pool->texture->x_south, \
		&pool->texture->y_south);
	else if (ft_strnstr(pool->map->texture_south + search_offset, ".png", 4))
		pool->texture->south = mlx_png_file_to_image(pool->mlx->ptr, \
		pool->map->texture_south, &pool->texture->x_south, \
		&pool->texture->y_south);
	free(pool->map->texture_south);
	pool->map->texture_south = NULL;
	pool->texture->address_south = mlx_get_data_addr(pool->texture->south, \
	&pool->texture->bpp_south, &pool->texture->ls_south, \
	&pool->texture->endian_south);
	if (!pool->texture->south || !pool->texture->address_south)
		exit_game("MLX failed to process texture 'SO'!\n", pool);
}

static void	set_texture_east(t_pool *pool)
{
	size_t	search_offset;

	search_offset = ft_strlen(pool->map->texture_east) - 4;
	if (ft_strnstr(pool->map->texture_east + search_offset, ".xpm", 4))
		pool->texture->east = mlx_xpm_file_to_image(pool->mlx->ptr, \
		pool->map->texture_east, &pool->texture->x_east, \
		&pool->texture->y_east);
	else if (ft_strnstr(pool->map->texture_east + search_offset, ".png", 4))
		pool->texture->east = mlx_png_file_to_image(pool->mlx->ptr, \
		pool->map->texture_east, &pool->texture->x_east, \
		&pool->texture->y_east);
	free(pool->map->texture_east);
	pool->map->texture_east = NULL;
	pool->texture->address_east = mlx_get_data_addr(pool->texture->east, \
	&pool->texture->bpp_east, &pool->texture->ls_east, \
	&pool->texture->endian_east);
	if (!pool->texture->east || !pool->texture->address_east)
		exit_game("MLX failed to process texture 'EA'!\n", pool);
}

static void	set_texture_west(t_pool *pool)
{
	size_t	search_offset;

	search_offset = ft_strlen(pool->map->texture_west) - 4;
	if (ft_strnstr(pool->map->texture_west + search_offset, ".xpm", 4))
		pool->texture->west = mlx_xpm_file_to_image(pool->mlx->ptr, \
		pool->map->texture_west, &pool->texture->x_west, \
		&pool->texture->y_west);
	else if (ft_strnstr(pool->map->texture_west + search_offset, ".png", 4))
		pool->texture->west = mlx_png_file_to_image(pool->mlx->ptr, \
		pool->map->texture_west, &pool->texture->x_west, \
		&pool->texture->y_west);
	free(pool->map->texture_west);
	pool->map->texture_west = NULL;
	pool->texture->address_west = mlx_get_data_addr(pool->texture->west, \
	&pool->texture->bpp_west, &pool->texture->ls_west, \
	&pool->texture->endian_west);
	if (!pool->texture->west || !pool->texture->address_west)
		exit_game("MLX failed to process texture 'WE'!\n", pool);
}

void		set_textures(t_pool *pool)
{
	size_t	search_offset;

	set_texture_north(pool);
	set_texture_south(pool);
	set_texture_east(pool);
	set_texture_west(pool);
	search_offset = ft_strlen(pool->map->texture_sprite) - 4;
	if (ft_strnstr(pool->map->texture_sprite + search_offset, ".xpm", 4))
		pool->texture->sprite = mlx_xpm_file_to_image(pool->mlx->ptr, \
		pool->map->texture_sprite, &pool->texture->x_sprite, \
		&pool->texture->y_sprite);
	else if (ft_strnstr(pool->map->texture_sprite + search_offset, ".png", 4))
		pool->texture->sprite = mlx_png_file_to_image(pool->mlx->ptr, \
		pool->map->texture_sprite, &pool->texture->x_sprite, \
		&pool->texture->y_sprite);
	free(pool->map->texture_sprite);
	pool->map->texture_sprite = NULL;
	pool->texture->address_sprite = mlx_get_data_addr(pool->texture->sprite, \
	&pool->texture->bpp_sprite, &pool->texture->ls_sprite, \
	&pool->texture->endian_sprite);
	if (!pool->texture->sprite || !pool->texture->address_sprite)
		exit_game("MLX failed to process texture 'S'!\n", pool);
}
