/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_maps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebz <gebz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 02:48:09 by gibz              #+#    #+#             */
/*   Updated: 2025/02/18 12:11:49 by gebz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rtg_maps(t_maps *map, int fd, int *f_line, int *n_line)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	if (line == NULL)
		error("error 5");
	map->s = ft_split(line, '\n');
	map->tempo = ft_split(line, '\n');
	if (map->s == NULL || map->tempo == NULL)
		error("error 3");
	*f_line = ft_strlen(map->s[0]);
	while (map->s[(*n_line)])
	{
		len = ft_strlen(map->s[(*n_line)]);
		if (len != (*f_line))
		{
			free(line);
			error("error 4");
		}
		(*n_line)++;
	}
	free(line);
}

int	check_first_line(t_maps *map)
{
	int	y;

	y = 0;
	while (map->s[0][y])
	{
		if (map->s[0][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_last_line(t_maps *map, int n_line)
{
	int	y;

	y = 0;
	while (map->s[n_line - 1][y])
	{
		if (map->s[n_line - 1][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_first_char(t_maps *map)
{
	int	x;

	x = 1;
	while (map->s[x])
	{
		if (map->s[x][0] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_last_char(t_maps *map)
{
	int	y;
	int	x;

	y = ft_strlen(map->s[0]);
	x = 1;
	y--;
	while (map->s[x])
	{
		if (map->s[x][y] != '1')
			return (0);
		x++;
	}
	return (1);
}
