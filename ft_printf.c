/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-25 07:10:11 by shashemi          #+#    #+#             */
/*   Updated: 2024-09-25 07:10:11 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	handle_char(char const *format, va_list argptr, int *count)
{
	int	aux;

	if (*format == 'c')
	{
		aux = va_arg(argptr, int);
		*count += write(1, &aux, 1);
	}
	else if (*format == 's')
		ft_putstr(va_arg(argptr, char *), count);
}

static void	handle_pointer(char const *format, va_list argptr, int *count)
{
	unsigned long long	addr;

	if (*format == 'p')
	{
		addr = va_arg(argptr, unsigned long long);
		if (addr == 0)
		{
			*count += write(1, "(nil)", 5);
			return ;
		}
		*count += write(1, "0x", 2);
		print_base(addr, "0123456789abcdef", 16, count);
	}
}

static void	handle_numbers(char const *format, va_list argptr, int *count)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(argptr, int), count);
	else if (*format == 'u')
		print_base(va_arg(argptr, unsigned int), "0123456789", 10, count);
	else if (*format == 'x')
		print_base(va_arg(argptr, unsigned int), "0123456789abcdef", 16, count);
	else if (*format == 'X')
		print_base(va_arg(argptr, unsigned int), "0123456789ABCDEF", 16, count);
}

static void	parse_format(char const *format, va_list argptr, int *count)
{
	if (*format == 'c' || *format == 's')
		handle_char(format, argptr, count);
	else if (*format == 'p')
		handle_pointer(format, argptr, count);
	else if (*format == 'd' || *format == 'i' || *format == 'u'
		|| *format == 'x' || *format == 'X')
		handle_numbers(format, argptr, count);
	else if (*format == '%')
		*count += write(1, "%", 1);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	argptr;

	count = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			parse_format(++format, argptr, &count);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(argptr);
	return (count);
}
