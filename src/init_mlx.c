/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 03:15:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->window = NULL;
	mlx->old_image = NULL;
	mlx->new_image = NULL;
	mlx->render_status = 1;
	mlx->endian = 0;
	mlx->address = NULL;
	mlx->bits_per_pixel = 0;
	mlx->size_line = 0;
}
