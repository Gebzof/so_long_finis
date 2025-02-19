/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:11:05 by gpichon           #+#    #+#             */
/*   Updated: 2025/02/19 12:08:26 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_image(t_maps *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->p);
	mlx_destroy_image(ptr->mlx, ptr->floor);
	mlx_destroy_image(ptr->mlx, ptr->wall);
	mlx_destroy_image(ptr->mlx, ptr->e);
	mlx_destroy_image(ptr->mlx, ptr->c);
}

void	free_all_tab(t_maps *map)
{
	ft_free_tab(map->s);
	ft_free_tab(map->tempo);
}

void	reset_floor(t_maps *ptr, int x, int y, char str)
{
	int	m;

	m = 32;
	if (str == 'l')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor, y * m, x * m);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p, (y - 1) * m, x * m);
	}
	else if (str == 'r')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor, y * m, x * m);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p, (y + 1) * m, x * m);
	}
	else if (str == 'u')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor, y * m, x * m);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p, y * m, (x - 1) * m);
	}
	else
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor, y * m, x * m);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p, y * m, (x + 1) * m);
	}
}
