/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sprite.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/09 07:13:04 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_sprite(t_sprite *sprite)
{
	sprite->entity = NULL;
	sprite->distance = NULL;
	sprite->position_x = 0;
	sprite->position_y = 0;
	sprite->inv = 0;
	sprite->transform_x = 0;
	sprite->transform_y = 0;
	sprite->screen_x = 0;
	sprite->height = 0;
	sprite->width = 0;
	sprite->start_x = 0;
	sprite->start_y = 0;
	sprite->end_x = 0;
	sprite->end_y = 0;
	sprite->number = 0;
	sprite->stripe = 0;
	sprite->texture_x = 0;
	sprite->texture_y = 0;
}
