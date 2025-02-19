# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 09:56:10 by gebz              #+#    #+#              #
#    Updated: 2025/02/13 15:36:36 by gpichon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS =  ft_printf.c\
		printf_fonctions_char.c\
		printf_fonctions_int.c

OBJS = $(SRCS:.c=.o)

.PHONY = re fclean clean all

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

%.o:%.c
		@$(CC) $(CFLAGS) -c $< -o $@
$(NAME):$(OBJS)
		ar -rcs $(NAME) $(OBJS)
clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all
