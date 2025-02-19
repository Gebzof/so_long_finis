NAME = so_long

SRCS =	srcs/so_long_check_elements.c\
		srcs/so_long_main_fonction.c\
		srcs/so_long_check_eror.c\
		srcs/so_long_check_maps.c\
		srcs/so_long_utils.c\
		srcs/so_long_moovement.c\
		srcs/so_long_utils2.c

LIBFTAR = 	libft/libft.a

PRINTFAR = 	ft_printf/ft_printf.a

MLXAR = minilibx-linux/libmlx_Linux.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3

CC = cc

.PHONY = re fclean clean all

all : $(NAME)

%.o: %.C
	@$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@
	@$(CC) $(CFLAGS) $(SRCS) -c $< -o $@

$(NAME): $(LIBFTAR) $(MLXAR) $(PRINTFAR) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTAR) $(MLXAR) $(PRINTFAR) -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFTAR) :
	 make -C libft

$(MLXAR) :
	git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
	make -C minilibx-linux

$(PRINTFAR) :
		 make -C ft_printf

clean :
	rm -f $(OBJS)
	rm -f $(NAME)
	make clean -C minilibx-linux
	make clean -C libft
	make clean -C ft_printf

fclean : clean
	make fclean -C libft
	rm -rf minilibx-linux
	make fclean -C ft_printf

re : fclean all