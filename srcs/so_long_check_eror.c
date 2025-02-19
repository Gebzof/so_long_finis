/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_eror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:32:01 by gibz              #+#    #+#             */
/*   Updated: 2025/02/19 12:08:48 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char	*str)
{
	ft_printf("%s\n", str);
	exit(1);
}

char	*get_next_line(int fd)
{
	char	save[1500000];
	char	buff[1];
	int		i;

	i = 0;
	save[0] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\0')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	return (ft_strdup(save));
}

int	check_way(t_maps *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->s[x])
	{
		y = 0;
		while (map->s[x][y])
		{
			if (map->s[x][y] == 'P')
			{
				if (way(map, x, y) == 1)
					return (1);
				else
					return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	way_code(char **tab, int x, int y)
{
	if (tab[x][y] == '1' || tab[x][y] == 'F' || tab[x][y] == 'X')
	{
		return ;
	}
	else if ((tab[x][y] == 'C') && (tab[x + 1][y] == 'X' || tab[x - 1][y] == 'X'
		|| tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
	{
		if (tab[x + 1][y] != 'F' && tab[x - 1][y] != 'F'
			&& tab[x][y - 1] != 'F' && tab[x][y + 1] != 'F')
			return ;
	}
	if (tab[x][y] == 'E')
	{
		tab[x][y] = 'X';
		return ;
	}
	tab[x][y] = 'F';
	way_code(tab, x - 1, y);
	way_code(tab, x + 1, y);
	way_code(tab, x, y + 1);
	way_code(tab, x, y - 1);
}

int	way(t_maps *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	way_code(map->tempo, x, y);
	while (map->tempo[i])
	{
		j = 0;
		while (map->tempo[i][j])
		{
			if (map->tempo[i][j] == 'C' || map->tempo[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	ft_free_tab(map->tempo);
	return (1);
}
