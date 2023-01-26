/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 16:46:59 by dkrecisz      #+#    #+#                 */
/*   Updated: 2019/11/19 17:11:56 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*init_nzero(char *res)
{
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static char	*init_str(char *res, long long x, int size)
{
	long long	i;

	res[size] = '\0';
	if (x < 0)
	{
		x *= -1;
		res[0] = '-';
	}
	while (x != 0)
	{
		i = x;
		i %= 10;
		size--;
		res[size] = i + '0';
		x /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int			size;
	long long	x;
	char		*res;

	x = (long long)n;
	size = calc_size(n);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
		return (init_nzero(res));
	return (init_str(res, x, size));
}
