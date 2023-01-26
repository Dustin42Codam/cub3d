/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_save.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 20:28:05 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/06/18 14:55:32 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	check_save(const char *s1, const char *s2, int n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (i < n && c1[i] == c2[i] && c1[i] && c2[i])
		i++;
	if (s1[i])
		return (-1);
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}
