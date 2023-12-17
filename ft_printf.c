/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:27:12 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/17 02:27:13 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO:
// implement: cspdiuxX %
// Tienes que implementar las siguientes conversiones:
// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.

// TO DELIVER:
// Makefile, *.h, */*.h, *.c, */*.c
// libftprintf.a

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef int (*Printer)(int, int);

void	ft_printf(char const *container, ...)
{
	int	idx;
	va_list	args;

	Printer content_printers[256] = {0};

	content_printers['d'] = ft_putnbr_fd;
	content_printers['%'] = ft_putchar_fd;

	va_start(args, container);

	idx = -1;
	while (container[++idx])
	{
		if (container[idx] == '%') 
		{
			idx++;
			if (ft_strchr("djk", container[idx]))
				content_printers[(char)container[idx]](va_arg(args, int), 1);
			else if (ft_strchr("s", container[idx]))
			{
				ft_putstr_fd(va_arg(args, char*), 1);
			}
			else if (container[idx] == '%')
				ft_putchar_fd('%', 1);
}

		else
			ft_putchar_fd(container[idx], 1);
	}

	va_end(args);
}

int	main(void)
{
	ft_printf("n1: %d%%\nn2: %d%%\nn3: %d%%\n%%\n%s\n", 1, 2, 3, "hey");
	printf("original:\n");
	printf("n1: %d%%\nn2: %d%%\nn3: %d%%\n%%\n%s\n", 1, 2, 3, "heyyyyyy");
	return (0);
}
