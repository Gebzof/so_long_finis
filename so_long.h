/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:21:46 by gibz              #+#    #+#             */
/*   Updated: 2025/02/19 12:06:23 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"

typedef struct s_maps
{
	void	*mlx;
	void	*win;
	char	**s;
	char	**tempo;
	void	*p;
	void	*c;
	void	*e;
	void	*floor;
	void	*wall;
	int		p_count;
	int		e_count;
	int		steps;
}		t_maps;

void	init_value(t_maps *map, int *f_line, int *n_line);
void	map_modif(t_maps *map);

void	check_rtg_maps(t_maps *map, int fd, int *f_line, int *n_line);
int		check_ber(char *ber);
int		check_c(t_maps *map);
int		check_e(t_maps *map);
int		check_p(t_maps *map);

int		check_last_char(t_maps *map);
int		check_first_char(t_maps *map);
int		check_first_line(t_maps *map);
int		check_last_line(t_maps *map, int n_line);
void	check_valid_empty(char	*file, t_maps *map);
void	ft_free_tab(char **tab);

void	error(char *str);
int		key_hook(int key, t_maps *ptr);
int		destroy(t_maps *ptr);
void	init_xpm(t_maps	*map);
void	drawthemap(t_maps *map);
void	check_elment_init(t_maps *map, int x, int y);

void	destroy_image(t_maps *ptr);
void	moove_left(t_maps *ptr);
void	moove_up(t_maps *ptr);
void	moove_down(t_maps *ptr);
void	moove_rigth(t_maps *ptr);
int		way(t_maps *map, int x, int y);
int		check_way(t_maps *map);
char	*get_next_line(int fd);
void	free_all_tab(t_maps *map);
int		check_wall_and_c(t_maps *map, int x, int y);
void	reset_floor(t_maps *map, int x, int y, char str);

#endif