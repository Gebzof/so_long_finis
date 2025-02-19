# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 12:59:03 by gpichon           #+#    #+#              #
#    Updated: 2025/02/17 11:13:06 by gpichon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putendl_fd.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putnbr_fd.c  ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_flood_fill.c

.PHONY = re fclean clean all

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = cc

all : $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all