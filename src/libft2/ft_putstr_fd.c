/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:34:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/06/10 06:23:43 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	int ret;

	ret = 0;
	if (s != NULL)
	{
		ret = write(fd, s, ft_strlen(s));
		if (ret < 0)
			exit(0);
	}
}
