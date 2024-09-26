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

static void	parse_format2(char const *format, va_list argptr, int *count)
{
	char	aux;

	if (*format == 'd' || *format == 'i')
		ft_printnbr(va_arg(argptr, int), count);
	else if (*format == 'u')
		ft_printuns(va_arg(argptr, unsigned int), count);
	else if (*format == 'x')
		ft_printhexa((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789abcdef", count);
	else if (*format == 'X')
		ft_printhexa((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789ABCDEF", count);
	else
	{
		if (*format != '%')
			--format;
		aux = '%';
		*count += write(1, &aux, 1);
	}
}

static void	parse_format(char const *format, va_list argptr, int *count)
{
	unsigned long long	addr;
	int					aux;

	if (*format == 's')
		ft_printstr(va_arg(argptr, char *), count);
	else if (*format == 'c')
	{
		aux = va_arg(argptr, int);
		*count += write(1, &aux, 1);
	}
	else if (*format == 'p')
	{
		addr = va_arg(argptr, unsigned long long);
		if (addr == 0)
		{
			*count += write(1, "(nil)", 5);
			return ;
		}
		*count += write(1, "0x", 2);
		ft_printhexa(addr, "0123456789abcdef", count);
	}
	else
		parse_format2(format, argptr, count);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	int		flag;
	va_list	argptr;

	count = 0;
	va_start(argptr, format);
	while (*format)
	{
		flag = count;
		if (*format == '%' && *(format + 1))
		{
			++format;
			parse_format(format, argptr, &count);
		}
		else
		{
			count += write(1, format, 1);
		}
		if (flag > count)
			return (va_end(argptr), -1);
		++format;
	}
	return (va_end(argptr), count);
}
