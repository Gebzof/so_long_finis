/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:28 by gpichon           #+#    #+#             */
/*   Updated: 2025/01/22 11:34:41 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(char str, int base)
{
	char	base1[17];
	char	base2[17];

	base1[17] = "0123456789abcdef";
	base2[17] = "0123456789ABCDEF";
	while (base--)
		if (base1[base] == str || base2[base] == str)
			return (1);
	return (0);
}

int	check_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (check_base(str[i], str_base))
		result = result * str_base + (check_num(str[i++]));
	return (result * sign);
}
