/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-25 07:09:17 by shashemi          #+#    #+#             */
/*   Updated: 2024-09-25 07:09:17 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
void	ft_printnbr(int n, int *count);
void	ft_printstr(char *str, int *count);
void	ft_printuns(unsigned int nbr, int *count);
void	ft_printhexa(unsigned long long nbr, char *base, int *count);

#endif