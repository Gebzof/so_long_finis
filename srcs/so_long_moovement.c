/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moovement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:21:40 by gibz              #+#    #+#             */
/*   Updated: 2025/02/19 11:42:04 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moove_left(t_maps *ptr)
{
	int	x;
	int	y;

	x = 0;
	while (ptr->s[x])
	{
		y = 0;
		while (ptr->s[x][y])
		{
			if (ptr->s[x][y] == 'P')
			{
				if (check_wall_and_c(ptr, x, y - 1) == 1)
				{
					ptr->s[x][y] = '0';
					ptr->s[x][y - 1] = 'P';
					reset_floor(ptr, x, y, 'l');
					ptr->steps++;
					break ;
				}
			}
			y++;
		}
		x++;
	}
}

void	moove_up(t_maps *ptr)
{
	int	x;
	int	y;

	x = 0;
	while (ptr->s[x])
	{
		y = 0;
		while (ptr->s[x][y])
		{
			if (ptr->s[x][y] == 'P')
			{
				if (check_wall_and_c(ptr, x - 1, y) == 1)
				{
					ptr->s[x][y] = '0';
					ptr->s[x - 1][y] = 'P';
					reset_floor(ptr, x, y, 'u');
					ptr->steps++;
					break ;
				}
			}
			y++;
		}
		x++;
	}
}

void	moove_down(t_maps *ptr)
{
	int	x;
	int	y;

	x = 0;
	while (ptr->s[x])
	{
		y = 0;
		while (ptr->s[x][y])
		{
			if (ptr->s[x][y] == 'P')
			{
				if (check_wall_and_c(ptr, x + 1, y) == 1)
				{
					ptr->s[x][y] = '0';
					ptr->s[x + 1][y] = 'P';
					reset_floor(ptr, x, y, 'd');
					x += 2;
					ptr->steps++;
					break ;
				}
			}
			y++;
		}
		x++;
	}
}

void	moove_rigth(t_maps *ptr)
{
	int	x;
	int	y;

	x = 0;
	while (ptr->s[x])
	{
		y = 0;
		while (ptr->s[x][y])
		{
			if (ptr->s[x][y] == 'P')
			{
				if (check_wall_and_c(ptr, x, y + 1) == 1)
				{
					ptr->s[x][y] = '0';
					ptr->s[x][y + 1] = 'P';
					reset_floor(ptr, x, y, 'r');
					ptr->steps++;
					break ;
				}
			}
			y++;
		}
		x++;
	}
}

int	check_wall_and_c(t_maps *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (map->s[x][y] == '1')
		return (0);
	else if (map->s[x][y] == 'E')
	{
		while (map->s[i])
		{
			j = 0;
			while (map->s[i][j])
			{
				if (map->s[i][j] == 'C')
					return (0);
				j++;
			}
			i++;
		}
		destroy(map);
	}
	return (1);
}
