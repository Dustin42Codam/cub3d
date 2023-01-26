/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:54:03 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 05:04:10 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define ESCAPE 65307
#define FORWARD 119
#define BACKWARD 115
#define LEFT 97
#define RIGHT 100
#define ROTATE_LEFT 65361
#define ROTATE_RIGHT 65363

int	close_game(t_pool *pool)
{
	exit_game("Closing game!\n", pool);
	return (0);
}

int	key_press(int keycode, t_pool *pool)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == ESCAPE)
		close_game(pool);
	if (keycode == FORWARD && pool->data->backward == 0)
		pool->data->forward = 1;
	if (keycode == BACKWARD && pool->data->forward == 0)
		pool->data->backward = 1;
	if (keycode == LEFT && pool->data->right == 0)
		pool->data->left = 1;
	if (keycode == RIGHT && pool->data->left == 0)
		pool->data->right = 1;
	if (keycode == ROTATE_LEFT && pool->data->rotate_right == 0)
		pool->data->rotate_left = 1;
	if (keycode == ROTATE_RIGHT && pool->data->rotate_left == 0)
		pool->data->rotate_right = 1;
	return (0);
}

int	key_release(int keycode, t_pool *pool)
{
	if (keycode == FORWARD)
		pool->data->forward = 0;
	if (keycode == BACKWARD)
		pool->data->backward = 0;
	if (keycode == LEFT)
		pool->data->left = 0;
	if (keycode == RIGHT)
		pool->data->right = 0;
	if (keycode == ROTATE_LEFT)
		pool->data->rotate_left = 0;
	if (keycode == ROTATE_RIGHT)
		pool->data->rotate_right = 0;
	return (0);
}
