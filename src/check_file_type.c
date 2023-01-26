/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_file_type.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 18:22:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/06/10 04:41:25 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	check_file_type(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i > 4 && argv[i - 1] == 'b' && argv[i - 2] == 'u' && argv[i - 3] == 'c'
		&& argv[i - 4] == '.')
		return (1);
	return (0);
}
