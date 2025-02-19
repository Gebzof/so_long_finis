/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:02 by gebz              #+#    #+#             */
/*   Updated: 2024/11/28 11:44:25 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	check(char c, va_list *args, int *l, int *i);
void	ft_putchar(int c, int *l);
void	ft_putstr(char *str, int *l);
void	ft_putnbr(int nb, int *l);
void	ft_unsignedputnbr(unsigned int nb, int *l);
void	ft_putnbrhexa(unsigned int nb, char min_or_MAJ_or_ptr, int *l);
void	ft_putnbrptr(unsigned long int nb, int *l);
void	check_nb(unsigned long int nb, int *l);

#endif
