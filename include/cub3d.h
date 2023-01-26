/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 03:26:30 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/05 00:39:26 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define NORTH		1
# define SOUTH		2
# define WEST		3
# define EAST		4
# define SPRITE		5
# define FLOOR		6
# define CEILING	7
# define OUT_OF_MAP	9

# include <stddef.h>
# include <stdio.h>

typedef struct	s_img{
	int		line_y;
	int		line_start;
	int		line_end;
	int		wall_height;
	int		texture_x;
	int		texture_y;
	double	step;
	double	texture_pos;
}				t_img;

typedef struct	s_mlx{
	void	*ptr;
	void	*window;
	void	*old_image;
	void	*new_image;
	int		render_status;
	int		endian;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
}				t_mlx;

typedef struct	s_data{
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_x_old;
	double	direction_y;
	double	plane_x;
	double	plane_x_old;
	double	plane_y;
	double	delta_x;
	double	delta_y;
	double	*wall_distance;
	double	ray_x;
	double	ray_y;
	double	distance_y;
	double	distance_x;
	int		map_x;			
	int		map_y;
	int		step_y;
	int		step_x;
	int		hit;
	int		backward;
	int		forward;
	int		right;
	int		left;
	int		rotate_right;
	int		rotate_left;
	int		side;
	int		x;
	double	wall_x;
	int		wall_orientation;
	double	cam_x;
}				t_data;

typedef	struct	s_sprite
{
	double	**entity;
	double	*distance;
	double	position_x;
	double	position_y;
	double	inv;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		height;
	int		width;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		number;
	int		stripe;
	int		texture_x;
	int		texture_y;
}				t_sprite;

typedef struct	s_map
{
	int		index;
	char	**main_ptr;
	char	**path_ptr;
	int		res_x;
	int		res_y;
	int		max_x;
	int		max_y;
	char	*texture_north;
	char	*texture_west;
	char	*texture_east;
	char	*texture_south;
	char	*texture_sprite;
	int		start_pos_x;
	int		start_pos_y;
	int		floor;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	int		rgb_count;
	int		**area;
	int		**dummy;
	char	start_orientation;
	int		**check;
	int		screenshot;
	char	*field;
	int		rgb_comma;
	int		parse_check;
}				t_map;

typedef	struct	s_texture
{
	void	*south;
	char	*address_south;
	int		bpp_south;
	int		ls_south;
	int		endian_south;
	int		y_south;
	int		x_south;
	void	*west;
	char	*address_west;
	int		bpp_west;
	int		ls_west;
	int		endian_west;
	int		y_west;
	int		x_west;
	void	*north;
	char	*address_north;
	int		bpp_north;
	int		ls_north;
	int		endian_north;
	int		y_north;
	int		x_north;
	void	*east;
	char	*address_east;
	int		bpp_east;
	int		ls_east;
	int		endian_east;
	int		y_east;
	int		x_east;
	void	*sprite;
	char	*address_sprite;
	int		bpp_sprite;
	int		ls_sprite;
	int		endian_sprite;
	int		y_sprite;
	int		x_sprite;
}				t_texture;

typedef struct	s_pool
{
	t_img		*img;
	t_mlx		*mlx;
	t_map		*map;
	t_data		*data;
	t_sprite	*sprite;
	t_texture	*texture;
}				t_pool;

void			init_mlx(t_mlx *mlx);
void			init_img(t_img *img);
void			init_map(t_map *map);
void			init_area(t_map *map);
void			init_dummy(t_map *map);
void			init_data(t_data *data);
void			init_sprite(t_sprite *sprite);
void			init_textures(t_texture *texture);

int				check_file_type(char *argv);
int				check_save(const char *s1, const char *s2, size_t n);
void			check_screensize(t_pool *pool);

char			*read_map(t_pool *pool, char *map, int fd);

void			parser(t_pool *pool, t_map *map, char *file);
void			parse_resolution(t_pool *pool, t_map *map, char *map_string);
void			parse_textures(t_pool *pool, char *map_str, int type);
void			parse_sprite(t_pool *pool, char *map_str, int type);
void			parse_rgb(t_pool *pool, t_map *map, int target);
void			parse_map(t_pool *pool, t_map *map, char *map_string);

void			set_orientation(t_pool *pool, t_map *map);
void			set_sprites(t_pool *pool, t_map *map, t_sprite *sprite);
void			set_textures(t_pool *pool);

void			validate_dummy_map(t_pool *pool, t_map *map);
void			copy_map_to_dummy(t_pool *pool, t_map *map, char *map_str);

void			free_dummy(t_map *map);
void			free_map_area(t_map *map);
void			free_sprites(t_sprite *sprite);

int				loop_hooks(t_pool *pool);

int				key_press(int keycode, t_pool *pool);
int				key_release(int keycode, t_pool *pool);

void			player_move_forward(t_data *data, t_map *map);
void			player_move_backward(t_data *data, t_map *map);
void			player_move_right(t_data *data, t_map *map);
void			player_move_left(t_data *data, t_map *map);
void			player_rotate_left(t_data *data);
void			player_rotate_right(t_data *data);

void			create_new_image(t_pool *pool, t_mlx *mlx, t_map *map);
void			draw_ray_to_image(t_pool *pool);

void			cast_rays(t_pool *pool);
void			cast_sprites(t_pool *pool);
void			calculate_walls(t_pool *pool);

void			make_screenshot(t_pool *pool);

int				close_game(t_pool *pool);
void			exit_game(char *msg, t_pool *pool);

#endif
