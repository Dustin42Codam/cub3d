/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 15:55:18 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/02 21:06:23 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*init_string(char *map_str, char *buffer, char *concat_str)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (map_str[i] != '\0')
	{
		concat_str[i] = map_str[i];
		i++;
	}
	while (buffer[y] != '\0')
	{
		concat_str[i] = buffer[y];
		i++;
		y++;
	}
	concat_str[i] = '\0';
	return (concat_str);
}

static char	*concatinate_buffer(char *map_str, char *buffer)
{
	size_t	max_len;
	char	*concat_str;

	max_len = ft_strlen(map_str) + ft_strlen(buffer);
	concat_str = (char*)malloc(sizeof(char) * (max_len + 1));
	if (concat_str == NULL)
	{
		free(buffer);
		free(map_str);
		return (NULL);
	}
	concat_str = init_string(map_str, buffer, concat_str);
	free(buffer);
	free(map_str);
	return (concat_str);
}

char		*read_map(t_pool *pool, char *map, int fd)
{
	char	*buf;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		buf = (char*)malloc(sizeof(char) * 42 + 1);
		if (buf == NULL)
			exit_game("Memory allocation failed! [src/parser.c]\n", pool);
		ret = read(fd, buf, 42);
		if (ret < 0)
		{
			free(buf);
			exit_game("Memory allocation failed! [src/parser.c]\n", pool);
		}
		buf[ret] = '\0';
		map = concatinate_buffer(map, buf);
		if (map == NULL)
		{
			free(buf);
			exit_game("Memory allocation failed! [src/parser.c]\n", pool);
		}
	}
	return (map);
}
