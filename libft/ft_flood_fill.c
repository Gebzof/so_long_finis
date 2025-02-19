/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:58 by gpichon           #+#    #+#             */
/*   Updated: 2025/02/17 11:12:30 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill(char **tab, t_point size, t_point curr, int a_fill)
{
	if (curr.y >= size.y || curr.y < 0 || curr.x >= size.x
		|| curr.x < 0 || tab[curr.y][curr.x] != a_fill)
	{
		return ;
	}
	tab[curr.y][curr.x] = 'F';
	fill(tab, size, (t_point){curr.x + 1, curr.y}, a_fill);
	fill(tab, size, (t_point){curr.x - 1, curr.y}, a_fill);
	fill(tab, size, (t_point){curr.x, curr.y + 1}, a_fill);
	fill(tab, size, (t_point){curr.x, curr.y - 1}, a_fill);
}

void	ft_flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
