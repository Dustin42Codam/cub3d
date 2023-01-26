/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/09 06:36:56 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 23:54:19 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "../mlx/mlx.h"

static void	change_resolution(t_map *map, char choice)
{
	if (choice == '1')
	{
		map->res_x = 1280;
		map->res_y = 720;
		ft_putstr_fd("Resolution changed to 1280x720!\n", 1);
	}
	else if (choice == '2')
	{
		map->res_x = 1600;
		map->res_y = 900;
		ft_putstr_fd("Resolution changed to 1600x900!\n", 1);
	}
	else if (choice == '3')
	{
		map->res_x = 1920;
		map->res_y = 1080;
		ft_putstr_fd("Resolution changed to 1920x1080!\n", 1);
	}
}

static void	choose_resolution(t_pool *pool, t_map *map)
{
	char	choice;
	char	*buffer;
	int		read_return;

	choice = 0;
	ft_putstr_fd("\nChoose one of the following options: \n", 1);
	ft_putstr_fd("[1] 1280 x 720\n", 1);
	ft_putstr_fd("[2] 1600 x 900\n", 1);
	ft_putstr_fd("[3] 1920 x 1080\n", 1);
	while (choice != '1' && choice != '2' && choice != '3')
	{
		buffer = (char *)malloc(sizeof(char) * 1 + 1);
		if (buffer == NULL)
			exit_game("Malloc failed! [parse_resolution.c]\n", pool);
		buffer[1] = '\0';
		read_return = read(0, buffer, 1);
		if (read_return < 0)
		{
			free(buffer);
			exit_game("Reading failed! [parse_resolution.c]\n", pool);
		}
		choice = buffer[0];
		free(buffer);
	}
	change_resolution(map, choice);
}

static void	request_bigger_resolution(t_pool *pool, t_map *map)
{
	char	choice;
	char	*buffer;
	int		read_return;

	choice = 0;
	ft_putstr_fd("Small resolution!\nDo you want to change the values?\n", 1);
	ft_putstr_fd("Enter [Y]es or [n]o: ", 1);
	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		buffer = (char *)malloc(sizeof(char) * 1 + 1);
		if (buffer == NULL)
			exit_game("Malloc failed! [parse_resolution.c]\n", pool);
		buffer[1] = '\0';
		read_return = read(0, buffer, 1);
		if (read_return < 0)
		{
			free(buffer);
			exit_game("Reading failed! [parse_resolution.c]\n", pool);
		}
		choice = buffer[0];
		free(buffer);
	}
	if (choice == 'N' || choice == 'n')
		return ;
	choose_resolution(pool, map);
}

void		parse_resolution(t_pool *pool, t_map *map, char *map_string)
{
	if (map->res_y || map->res_x)
		exit_game("Invalid input for Resolution!\n", pool);
	map->index++;
	while (ft_strchr(" \t", map_string[map->index]))
		map->index++;
	if (!(ft_isdigit(map_string[map->index])))
		exit_game("Invalid X value for: Resolution!\n", pool);
	map->res_x = ft_atoi((const char *)map_string + map->index);
	map->index += ft_numlen(map->res_x);
	while (ft_strchr(" \t", map_string[map->index]))
		map->index++;
	if (!(ft_isdigit(map_string[map->index])))
		exit_game("Invalid Y value for: Resolution!\n", pool);
	map->res_y = ft_atoi((const char *)map_string + map->index);
	map->index += ft_numlen(map->res_y);
	while (ft_isspace(map_string[map->index]))
		map->index++;
	map->index--;
	if (map->res_x < 25 || map->res_y < 25)
		request_bigger_resolution(pool, map);
	ft_putstr_fd("\033[1;32mResolution:\t [SUCCESS]\033[0m\n", 1);
}
