/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 11:06:50 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 19:42:58 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_textures_tail(t_texture *texture)
{
	texture->east = 0;
	texture->address_east = 0;
	texture->bpp_east = 0;
	texture->ls_east = 0;
	texture->endian_east = 0;
	texture->x_east = 0;
	texture->y_east = 0;
	texture->sprite = 0;
	texture->address_sprite = 0;
	texture->bpp_sprite = 0;
	texture->ls_sprite = 0;
	texture->endian_sprite = 0;
	texture->x_sprite = 0;
	texture->y_sprite = 0;
}

void		init_textures(t_texture *texture)
{
	texture->north = 0;
	texture->address_north = 0;
	texture->bpp_north = 0;
	texture->ls_north = 0;
	texture->endian_north = 0;
	texture->x_north = 0;
	texture->y_north = 0;
	texture->south = 0;
	texture->address_south = 0;
	texture->bpp_south = 0;
	texture->ls_south = 0;
	texture->endian_south = 0;
	texture->x_south = 0;
	texture->y_south = 0;
	texture->west = 0;
	texture->address_west = 0;
	texture->bpp_west = 0;
	texture->ls_west = 0;
	texture->endian_west = 0;
	texture->x_west = 0;
	texture->y_west = 0;
	init_textures_tail(texture);
}
