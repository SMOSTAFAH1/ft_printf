/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-25 08:36:45 by shashemi          #+#    #+#             */
/*   Updated: 2024-09-25 08:36:45 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/// @brief Prints an unsigned number in stdout and counts the printed characters
/// @param nbr Number to print
/// @param count Pointer to the counter of printed characters
void	ft_printuns(unsigned int nbr, int *count)
{
	char	number;

	if (nbr / 10 != 0)
		ft_printuns((nbr / 10), count);
	number = nbr % 10 + '0';
	*count += write(1, &number, 1);
}

/// @brief Prints a number in hexadecimal format in stdout and counts 
/// the printed characters, either in minuscule or majuscule
/// @param nbr Number to print
/// @param base Used base for the number, either 
/// "0123456789abcdef" or "0123456789ABCDEF"
/// @param count Pointer to the counter of printed characters
void	ft_printhexa(unsigned long long nbr, char *base, int *count)
{
	char	number;

	if (nbr / 16 != 0)
		ft_printhexa((nbr / 16), base, count);
	number = base[nbr % 16];
	*count += write(1, &number, 1);
}

/// @brief Tweaked version of ft_putnbr_fd to print a number in stdout and 
/// count the printed characters, using ft_printuns for positive numbers
/// @param n 
/// @param count 
void	ft_printnbr(int n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			*count += 11;
			return ;
		}
		*count += write(1, "-", 1);
		n *= -1;
	}
	ft_printuns(n, count);
}

/// @brief Modified version of ft_putstr_fd to print a string
/// in stdout and count the printed characters
/// @param str String to print
/// @param count Pointer to the counter of printed characters
void	ft_printstr(char *str, int *count)
{
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		*count += write(1, str, 1);
		++str;
	}
}