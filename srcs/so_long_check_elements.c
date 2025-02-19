/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:50:39 by gibz              #+#    #+#             */
/*   Updated: 2025/02/19 12:07:32 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_p(t_maps *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->s[x])
	{
		y = 0;
		while (map->s[x][y])
		{
			if ((map->s[x][y] == 'P') && map->p_count < 1)
			{
				map->p_count = 1;
			}
			else if ((map->s[x][y] == 'P') && map->p_count == 1)
				return (free_all_tab(map), 0);
			y++;
		}
		x++;
	}
	if (map->p_count == 1)
		return (1);
	else
		return (free_all_tab(map), 0);
}

int	check_e(t_maps *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->s[x])
	{
		y = 0;
		while (map->s[x][y])
		{
			if ((map->s[x][y] == 'E') && map->e_count < 1)
			{
				map->e_count = 1;
			}
			else if ((map->s[x][y] == 'E') && map->e_count == 1)
				return (free_all_tab(map), 0);
			y++;
		}
		x++;
	}
	if (map->e_count == 1)
		return (1);
	else
		return (free_all_tab(map), 0);
}

int	check_c(t_maps *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->s[x])
	{
		y = 0;
		while (map->s[x][y])
		{
			if (map->s[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (free_all_tab(map), 0);
}

int	check_ber(char *ber)
{
	int	i;

	i = 0;
	while (ber[i])
		i++;
	if (ber[i] == '\0')
		if (ber[i - 1] == 'r')
			if (ber[i - 2] == 'e')
				if (ber[i - 3] == 'b')
					if (ber[i - 4] == '.')
						return (1);
	return (0);
}

void	check_valid_empty(char	*file, t_maps *map)
{
	if (check_p(map) == 0)
		error("error p");
	if (check_e(map) == 0)
		error("error e");
	if (check_c(map) == 0)
		error("error c");
	if (check_ber(file) == 0)
		error("not a .ber");
	else
		return ;
}
