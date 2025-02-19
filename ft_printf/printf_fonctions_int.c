/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fonctions_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:27:05 by gebz              #+#    #+#             */
/*   Updated: 2025/01/22 12:00:17 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *l)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*l) += 11;
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-', l);
		nb *= -1;
		ft_putnbr(nb, l);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, l);
		ft_putnbr(nb % 10, l);
	}
	else
		ft_putchar(nb + '0', l);
}

void	ft_unsignedputnbr(unsigned int nb, int *l)
{
	if (nb >= 10)
	{
		ft_unsignedputnbr(nb / 10, l);
		ft_unsignedputnbr(nb % 10, l);
	}
	else
		ft_putchar(nb + '0', l);
}

void	check_nb(unsigned long int nb, int *l)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		(*l) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*l) += 2;
	}
}

void	ft_putnbrptr(unsigned long int nb, int *l)
{
	char	*base;
	char	*hex;
	int		i;

	i = 0;
	hex = malloc(sizeof(char) * 6 + sizeof(int) * 10);
	if (!hex)
		return ;
	base = "0123456789abcdef";
	check_nb(nb, l);
	while (nb > 0)
	{
		hex[i++] = base[nb % 16];
		nb /= 16;
	}
	while (i--)
		ft_putchar(hex[i], l);
	free(hex);
}

void	ft_putnbrhexa(unsigned int nb, char min_or_MAJ_or_ptr, int *l)
{
	char	*base;
	char	*hex;
	int		i;

	i = 0;
	hex = malloc(sizeof(char) * 6 + sizeof(int) * 10);
	if (!hex)
		return ;
	if (min_or_MAJ_or_ptr == 'X')
		base = "0123456789ABCDEF";
	else if (min_or_MAJ_or_ptr == 'x')
		base = "0123456789abcdef";
	if (nb == 0)
		ft_putchar('0', l);
	while (nb > 0)
	{
		hex[i++] = base[nb % 16];
		nb /= 16;
	}
	while (i--)
		ft_putchar(hex[i], l);
	free(hex);
}
