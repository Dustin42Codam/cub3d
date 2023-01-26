/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 15:54:23 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/05 00:32:07 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft2/libft.h"
#include "../mlx/mlx.h"
#include <math.h>
#include <stdlib.h>


//DELETE LATER
#define DestroyNotify 17
#define KeyPress 2
#define KeyPressMask 0
#define KeyRelease 3
#define KeyReleaseMask 0

static void	set_window_events_hooks(t_pool *pool, t_mlx *mlx)
{
	mlx->window = mlx_new_window(mlx->ptr, pool->map->res_x, \
								pool->map->res_y, "cub3D");
	if (mlx->window == NULL)
		exit_game("MLX failed to initialize window pointer!\n", pool);
	mlx_hook(mlx->window, DestroyNotify, 0, &close_game, pool);
	mlx_hook(mlx->window, 2, 1L << 0, &key_press, pool);
	mlx_hook(mlx->window, 3, 1L << 1, &key_release, pool);
	mlx_loop_hook(mlx->ptr, &loop_hooks, pool);
	mlx_loop(mlx->ptr);
}

static void	start_mlx(t_pool *pool)
{
	t_texture	texture;
	t_mlx		mlx;
	t_img		img;

	init_mlx(&mlx);
	init_img(&img);
	init_textures(&texture);
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		exit_game("Failed to start MLX session!\n", pool);
	pool->mlx = &mlx;
	pool->img = &img;
	pool->texture = &texture;
	set_textures(pool);
	if (pool->map->screenshot == 1)
		make_screenshot(pool);
	check_screensize(pool);
	ft_putstr_fd("\033[1;34mStarting game engine...\n\033[0m", 1);
	set_window_events_hooks(pool, &mlx);
}

int			main(int argc, char *argv[])
{
	t_pool		pool;
	t_map		map;
	t_data		data;
	t_sprite	sprite;
	
	init_map(&map);
	init_data(&data);
	init_sprite(&sprite);
	pool.map = &map;
	pool.data = &data;
	pool.sprite = &sprite;
	if (argc == 3 && check_file_type(argv[1])
		&& (check_save(argv[2], "--save", 6) == 0))
		map.screenshot = 1;
	else if (argc == 3 && check_save(argv[2], "--save", 6) != 0)
		exit_game("Invalid arguments!\n", &pool);
	else if (argc == 1)
		exit_game("Too few arguments!\nTry: ./cub3D [FILE.cub]\n", &pool);
	else if (argc > 3)
		exit_game("Too many arguments!\n", &pool);
	else if (argc == 2 && !check_file_type(argv[1]))
		exit_game("Invalid map file provided!\n", &pool);
	parser(&pool, &map, argv[1]);
	start_mlx(&pool);
	return (0);
}
