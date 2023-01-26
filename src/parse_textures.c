/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/09 22:45:43 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 20:15:19 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

static void	check_for_redundant_texture(t_pool *pool, int type)
{
	if (type == NORTH && pool->map->texture_north)
		exit_game("Texture 'NO' is specified more than once!\n", pool);
	else if (type == SOUTH && pool->map->texture_south)
		exit_game("Texture 'SO' is specified more than once!\n", pool);
	else if (type == WEST && pool->map->texture_west)
		exit_game("Texture 'WE' is specified more than once!\n", pool);
	else if (type == EAST && pool->map->texture_east)
		exit_game("Texture 'EA' is specified more than once!\n", pool);
	else if (type == SPRITE && pool->map->texture_sprite)
		exit_game("Texture 'S' is specified more than once!\n", pool);
}

static char	*get_path(t_pool *pool, char *map_string, char *path)
{
	int	path_index;

	path_index = 0;
	while (ft_isprint(map_string[pool->map->index]))
	{
		path[path_index] = map_string[pool->map->index];
		pool->map->index++;
		path_index++;
	}
	if (ft_isspace(path[path_index - 1]))
	{
		path_index--;
		while (ft_isspace(path[path_index]))
		{
			path[path_index] = '\0';
			path_index--;
		}
	}
	else
		path[path_index] = '\0';
	return (path);
}

static void	init_path(t_pool *pool, char *map_string, int type, char *path)
{
	path = get_path(pool, map_string, path);
	if (open(path, O_RDONLY) < 0)
	{
		free((*pool->map->path_ptr));
		exit_game("Failed to open texture file! [parse_textures.c]\n", pool);
	}
	if (type == NORTH)
		pool->map->texture_north = path;
	if (type == SOUTH)
		pool->map->texture_south = path;
	if (type == WEST)
		pool->map->texture_west = path;
	if (type == EAST)
		pool->map->texture_east = path;
	if (type == SPRITE)
		pool->map->texture_sprite = path;
}

void		parse_textures(t_pool *pool, char *map_str, int type)
{
	int		tmp_index;
	int		path_len;
	char	*path;

	path_len = 0;
	path = NULL;
	pool->map->path_ptr = &path;
	check_for_redundant_texture(pool, type);
	pool->map->index += 2;
	if (!(ft_strchr(" .\t", map_str[pool->map->index])))
		exit_game("Invalid texture data! [parse_textures.c]\n", pool);
	while (ft_strchr("\t ", map_str[pool->map->index]))
		pool->map->index++;
	tmp_index = pool->map->index;
	while (!(ft_isspace(map_str[tmp_index])))
		tmp_index++;
	path_len += tmp_index;
	path = (char*)malloc(sizeof(char) * (path_len + 1));
	if (path == NULL)
		exit_game("Memory allocation failed! [parse_textures.c]\n", pool);
	init_path(pool, map_str, type, path);
	if (pool->map->texture_north && pool->map->texture_south && \
		pool->map->texture_east && pool->map->texture_west && \
		pool->map->texture_sprite)
		ft_putstr_fd("\033[1;32mTextures:\t [SUCCESS]\033[0m\n", 1);
}

void		parse_sprite(t_pool *pool, char *map_str, int type)
{
	int		tmp_index;
	int		path_len;
	char	*path;

	path_len = 0;
	path = NULL;
	pool->map->path_ptr = &path;
	check_for_redundant_texture(pool, type);
	pool->map->index++;
	if (!(ft_strchr(" .\t", map_str[pool->map->index])))
		exit_game("Invalid sprite data! [parse_textures.c]\n", pool);
	while (ft_strchr("\t ", map_str[pool->map->index]))
		pool->map->index++;
	tmp_index = pool->map->index;
	while (!(ft_isspace(map_str[tmp_index])))
		tmp_index++;
	path_len += tmp_index;
	path = (char*)malloc(sizeof(char) * (path_len + 1));
	if (path == NULL)
		exit_game("Memory allocation failed! [parse_textures.c]\n", pool);
	init_path(pool, map_str, type, path);
	if (pool->map->texture_north && pool->map->texture_south && \
		pool->map->texture_east && pool->map->texture_west && \
		pool->map->texture_sprite)
		ft_putstr_fd("\033[1;32mTextures:\t [SUCCESS]\033[0m\n", 1);
}
