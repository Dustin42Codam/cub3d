/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rgb.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 05:26:34 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	check_errors(t_pool *pool, char c)
{
	if (pool->map->rgb_count > 3)
		exit_game("Too many RGB values!\n", pool);
	if (pool->map->rgb_comma != 2)
		exit_game("Invalid RGB format!\n", pool);
	if (pool->map->rgb_comma == 3 && c != '\n')
		exit_game("Invalid RGB format!\n", pool);
}

static int	merge_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static void	set_rgb(t_pool *pool, int value, int target)
{
	if (value < 0 || value > 255)
		exit_game("Invalid RGB value!\n", pool);
	else if (target == FLOOR)
	{
		if (pool->map->rgb_count == 1 || pool->map->rgb_count == 4)
			pool->map->floor_r = value;
		else if (pool->map->rgb_count == 2 || pool->map->rgb_count == 5)
			pool->map->floor_g = value;
		else if (pool->map->rgb_count == 3 || pool->map->rgb_count == 6)
			pool->map->floor_b = value;
	}
	else if (target == CEILING)
	{
		if (pool->map->rgb_count == 1 || pool->map->rgb_count == 4)
			pool->map->ceiling_r = value;
		else if (pool->map->rgb_count == 2 || pool->map->rgb_count == 5)
			pool->map->ceiling_g = value;
		else if (pool->map->rgb_count == 3 || pool->map->rgb_count == 6)
			pool->map->ceiling_b = value;
	}
}

static void	validate_order(t_pool *pool, char *str, int i, int target)
{
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			pool->map->rgb_count++;
			set_rgb(pool, ft_atoi(str + i), target);
			i += ft_numlen(ft_atoi(str + i));
		}
		while (ft_isspace(str[i]) && str[i] != '\n')
			i++;
		while (str[i] == ',')
		{
			pool->map->rgb_comma++;
			i++;
		}
		while (ft_isspace(str[i]) && str[i] != '\n')
			i++;
		if (pool->map->rgb_comma < 2 && pool->map->rgb_count >= 2)
			exit_game("Invalid RGB format!\n", pool);
		if (!(ft_isdigit(str[i])) && !(ft_isspace(str[i])) && str[i] != ',')
			exit_game("Invalid character in RGB line!\n", pool);
	}
	pool->map->index = i;
	check_errors(pool, str[i]);
}

void		parse_rgb(t_pool *pool, t_map *map, int target)
{
	map->rgb_comma = 0;
	map->rgb_count = 0;
	if ((target == FLOOR && map->floor >= 0) || \
		(target == CEILING && map->ceiling >= 0))
		exit_game("Floor/Ceiling RGB is specified more than once!\n", pool);
	map->index++;
	while (ft_strchr(" \t", (*pool->map->main_ptr)[map->index]))
		map->index++;
	if (!(ft_isdigit((*pool->map->main_ptr)[map->index])))
		exit_game("Invalid RGB data!\n", pool);
	validate_order(pool, (*pool->map->main_ptr), map->index, target);
	if ((target == FLOOR && map->rgb_count == 3) || \
		(target == FLOOR && map->rgb_count == 6))
		map->floor = merge_rgb(map->floor_r, map->floor_g, map->floor_b);
	if ((target == CEILING && map->rgb_count == 3) || \
		(target == CEILING && map->rgb_count == 6))
		map->ceiling = merge_rgb(map->ceiling_r, map->ceiling_g, \
								map->ceiling_b);
	if (map->floor >= 0 && map->ceiling >= 0)
	{
		map->parse_check = 1;
		ft_putstr_fd("\033[1;32mRGB colors:\t [SUCCESS]\033[0m\n", 1);
	}
}
