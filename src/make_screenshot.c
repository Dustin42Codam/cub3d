/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_screenshot.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 14:37:11 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void	generate_bmp_header(t_pool *pool, int fd)
{
	unsigned int	resolution;
	int				ret;

	ret = write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	if (ret < 0)
		exit_game("Writing the BMP header failed!\n", pool);
	ret = write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	if (ret < 0)
		exit_game("Writing the BMP header failed!\n", pool);
	resolution = (unsigned int)pool->map->res_x;
	ret = write(fd, &resolution, 4);
	if (ret < 0)
		exit_game("Writing the BMP header failed!\n", pool);
	resolution = (unsigned int)pool->map->res_y;
	ret = write(fd, &resolution, 4);
	if (ret < 0)
		exit_game("Writing the BMP header failed!\n", pool);
	ret = write(fd, "\x01\x00\x18\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\
		\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 28);
	if (ret < 0)
		exit_game("Writing the BMP header failed!\n", pool);
}

static void	generate_bmp_image(t_pool *pool, int fd, int line, int row)
{
	int	padding;
	int	ret;
	int	color;
	int	rgb;

	padding = pool->map->res_x % 4;
	while (line >= 0)
	{
		row = 0;
		while (row < pool->map->res_x)
		{
			color = *(int*)(pool->mlx->address + \
			(line * pool->mlx->size_line) + \
			(row * (pool->mlx->bits_per_pixel / 8)));
			rgb = color & 0x00FFFFFF;
			ret = write(fd, &rgb, 3);
			if (ret < 0)
				exit_game("Writing BMP image failed!\n", pool);
			row++;
		}
		ret = write(fd, "\x00\x00\x00", padding);
		if (ret < 0)
			exit_game("Writing BMP image failed!\n", pool);
		line--;
	}
}

void		make_screenshot(t_pool *pool)
{
	int	fd;
	int	line;
	int	row;

	row = 0;
	line = pool->map->res_y - 1;
	fd = open("screenshot.bmp", (O_WRONLY | O_CREAT | O_TRUNC | O_APPEND), \
									00644);
	if (fd == -1)
		exit_game("Creating screenshot failed!\n", pool);
	create_new_image(pool, pool->mlx, pool->map);
	cast_rays(pool);
	generate_bmp_header(pool, fd);
	generate_bmp_image(pool, fd, line, row);
	exit_game("Screenshot created and saved in root directory!\n", pool);
}
