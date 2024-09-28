/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 07:49:20 by shashemi          #+#    #+#             */
/*   Updated: 2024-09-28 07:49:20 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello, %s!\n", "World");
	ft_printf("Hello, %s!\n", "World");
	ft_printf("%d\n", 0);
	ft_printf("%c\n", 'A');
	ft_printf("%s\n", "Hola");
	ft_printf("%p\n", (void *)0x12345678);
	ft_printf("%d\n", 123);
	ft_printf("%i\n", -123);
	ft_printf("%u\n", 123);
	ft_printf("%x\n", 123);
	ft_printf("%X\n", 123);
	return (0);
}
