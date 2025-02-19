/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:21:43 by gibz              #+#    #+#             */
/*   Updated: 2025/02/19 16:41:43 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy(t_maps *ptr)
{
	destroy_image(ptr);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	ft_free_tab(ptr->s);
	exit(0);
}

/*
	65307 = echap
	97 = a
	119 = w
	115 = s
	100 = d
*/

int	key_hook(int key, t_maps *ptr)
{
	int	temp;

	temp = ptr->steps;
	if (key == 65307)
		destroy(ptr);
	else if (key == 97)
		moove_left(ptr);
	else if (key == 119)
		moove_up(ptr);
	else if (key == 115)
		moove_down(ptr);
	else if (key == 100)
		moove_rigth(ptr);
	else
		return (1);
	if (ptr->steps == 1)
		ft_printf("first step \n");
	else if (ptr->steps != temp)
		ft_printf("%d steps \n", ptr->steps);
	return (0);
}

void	init_xpm(t_maps	*map)
{
	int	w;
	int	h;

	map->p = mlx_xpm_file_to_image(map->mlx, "xpm/player.xpm", &w, &h);
	map->e = mlx_xpm_file_to_image(map->mlx, "xpm/Exit.xpm", &w, &h);
	map->c = mlx_xpm_file_to_image(map->mlx, "xpm/item.xpm", &w, &h);
	map->floor = mlx_xpm_file_to_image(map->mlx, "xpm/floor.xpm", &w, &h);
	map->wall = mlx_xpm_file_to_image(map->mlx, "xpm/wall.xpm", &w, &h);
	if (!map->p || !map->e || !map->c || !map->floor || !map->wall)
	{
		mlx_destroy_image(map->mlx, map->p);
		if (map->e)
			mlx_destroy_image(map->mlx, map->e);
		if (map->c)
			mlx_destroy_image(map->mlx, map->c);
		if (map->floor)
			mlx_destroy_image(map->mlx, map->floor);
		if (map->wall)
			mlx_destroy_image(map->mlx, map->wall);
		ft_free_tab(map->s);
		mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		error("image");
	}
}

void	check_elment_init(t_maps *map, int x, int y)
{
	if (map->s[x][y] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->p, y * 32, x * 32);
	else if (map->s[x][y] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->c, y * 32, x * 32);
	else if (map->s[x][y] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->floor, y * 32, x * 32);
	else if (map->s[x][y] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, y * 32, x * 32);
	else if (map->s[x][y] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->e, y * 32, x * 32);
	else
		destroy(map);
}

void	drawthemap(t_maps *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->s[x])
	{
		y = 0;
		while (map->s[x][y])
		{
			check_elment_init(map, x, y);
			y++;
		}
		x++;
	}
}
