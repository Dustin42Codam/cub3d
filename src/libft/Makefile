# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/15 19:33:12 by dkrecisz      #+#    #+#                  #
#    Updated: 2020/07/03 17:31:21 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putstr_fd.c ft_atoi.c ft_isspace.c ft_isdigit.c ft_strchr.c \
		ft_memchr.c ft_numlen.c  ft_bzero.c ft_calloc.c ft_memset.c \
		ft_strnstr.c ft_strncmp.c ft_strlen.c ft_isprint.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
