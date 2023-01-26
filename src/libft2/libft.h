/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:10:15 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/07/03 17:31:36 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

void			ft_putstr_fd(const char *s, int fd);
int				ft_atoi(const char *str);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_strchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_numlen(long n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strnstr(const char *haystack, \
				const char *needle, size_t len);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
