/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_img.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 03:15:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_img(t_img *img)
{
	img->line_y = 0;
	img->line_start = 0;
	img->line_end = 0;
	img->wall_height = 0;
	img->texture_x = 0;
	img->texture_y = 0;
	img->step = 0;
	img->texture_pos = 0;
}
