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

static void	print_number_base(unsigned long long nbr, const char *base,
				int base_len, int *count)
{
	char	buffer[65];
	int		i;

	i = 64;
	buffer[i] = '\0';
	if (nbr == 0)
		buffer[--i] = base[0];
	while (nbr)
	{
		buffer[--i] = base[nbr % base_len];
		nbr /= base_len;
	}
	*count += write(1, &buffer[i], 64 - i);
}

void	ft_printnbr(int n, int *count)
{
	int	len_before;

	len_before = *count;
	ft_putnbr_fd(n, 1);
	*count += (*count - len_before);
}

void	ft_printuns(unsigned int nbr, int *count)
{
	print_number_base(nbr, "0123456789", 10, count);
}

void	ft_printhexa(unsigned long long nbr, const char *base, int *count)
{
	print_number_base(nbr, base, 16, count);
}

void	ft_printstr(char *str, int *count)
{
	int	len;

	len = 0;
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	*count += len;
}
