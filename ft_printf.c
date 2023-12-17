/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:33:47 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/17 23:59:29 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./libft/libft.h"


ssize_t	ft_printf(char const *container, ...)
{
	va_list	args;
	size_t	len;

	va_start(args, container);

	len = 0;
	while (*container)
	{
		if (*container == '%')
		{
			container++;
			if (ft_strchr("di", *container))
				len += ft_signed_int_putnbr(va_arg(args, int));
			if (*container == 'u')
				len += ft_uint_putnbr(va_arg(args, unsigned int));
			if (*container == 's')
				len += ft_putstr(va_arg(args, char *));
			if (*container == 'c')
				len += ft_putchar(va_arg(args, int));
			if (*container == '%' )
				len += ft_putchar(*container);
					
		}
		else
			len += ft_putchar(*container);
		container++;
	}
	return (len);
}

int	main(void)
{
	printf("============\n");
	size_t len_mine = ft_printf("%s: %d%%\nThis is a null line: %s\n", "print my nummber", -42, NULL);
	printf("============\n");
	size_t len_orig = printf("%s: %d%%\nThis is a null line: %s\n", "print my nummber", -42, NULL);
	printf("============\n");
	ft_printf("my negative unsigned %u\n", -2);
	printf("negative unsigned %u\n", -2);
	printf("============\n");

	printf("len mine: %zu\nlen orig: %zu\n", len_mine, len_orig);
	return (0);
}