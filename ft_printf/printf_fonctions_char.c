/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fonctions_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:04:31 by gebz              #+#    #+#             */
/*   Updated: 2025/01/22 11:59:58 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *l)
{
	char	d;

	d = (char)c;
	write(1, &d, 1);
	(*l)++;
}

void	ft_putstr(char *str, int *l)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*l) += 6;
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*l)++;
	}
}
