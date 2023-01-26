/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/09 07:31:00 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/06/09 07:31:01 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(long n)
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
