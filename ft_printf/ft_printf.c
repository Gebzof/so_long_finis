/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:56:07 by gebz              #+#    #+#             */
/*   Updated: 2025/01/22 11:59:49 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check(char c, va_list *args, int *l, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), l);
	else if (c == 's')
		ft_putstr(va_arg(*args, char *), l);
	else if (c == 'p')
		ft_putnbrptr(va_arg(*args, unsigned long int), l);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), l);
	else if (c == 'u')
		ft_unsignedputnbr(va_arg(*args, unsigned int), l);
	else if (c == 'x')
		ft_putnbrhexa(va_arg(*args, unsigned int), 'x', l);
	else if (c == 'X')
		ft_putnbrhexa(va_arg(*args, unsigned int), 'X', l);
	else if (c == '%')
		ft_putchar('%', l);
	else
	{
		ft_putchar('%', l);
		(*i)--;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check(str[i], &args, &l, &i);
		}
		else
		{
			ft_putchar(str[i], &l);
		}
		i++;
	}
	va_end(args);
	return (l);
}
