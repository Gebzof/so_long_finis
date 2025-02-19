/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_fonction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:21:37 by gibz              #+#    #+#             */
/*   Updated: 2025/02/19 15:52:08 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_valid_maps(t_maps *map, int n_line)
{
	if (check_first_line(map) == 0)
		return (free_all_tab(map), 0);
	if (check_last_line(map, n_line) == 0)
		return (free_all_tab(map), 0);
	if (check_first_char(map) == 0)
		return (free_all_tab(map), 0);
	if (check_last_char(map) == 0)
		return (free_all_tab(map), 0);
	if (check_way(map) == 0)
		return (free_all_tab(map), 0);
	return (1);
}

void	init_value(t_maps *map, int *f_line, int *n_line)
{

	*f_line = 0;
	*n_line = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->steps = 0;
	map->c = NULL;
	map->p = NULL;
	map->wall = NULL;
	map->floor = NULL;
	map->e = NULL;
	map->s = NULL;
}

void	map_modif(t_maps *map)
{
	init_xpm(map);
	drawthemap(map);
	mlx_hook(map->win, 17, 0, destroy, map);
	mlx_key_hook(map->win, key_hook, map);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	t_maps	map;
	int		fd;
	int		f_line;
	int		n_line;

	if (ac != 2)
		error("argument");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("error 1");
	init_value(&map, &f_line, &n_line);
	check_rtg_maps(&map, fd, &f_line, &n_line);
	close(fd);
	check_valid_empty(av[1], &map);
	if (check_valid_maps(&map, n_line) == 0)
		error("error 2");
	map.mlx = mlx_init();
	if (!map.mlx)
		return (ft_free_tab(map.s), 0);
	if (f_line * 32 > 1920 || n_line * 32 > 1080)
		error("not a good size");
	map.win = mlx_new_window(map.mlx, f_line * 32, n_line * 32, "so_long");
	map_modif(&map);
	mlx_loop(map.mlx);
	return (0);
}
