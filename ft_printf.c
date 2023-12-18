/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:33:47 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/18 18:26:55 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./libft/libft.h"

#define hex "0123456789abcdef"
#define HEX "0123456789ABCDEF"

size_t  ft_putnbr_rec(int n, size_t len)
{
	ssize_t nbr;

	nbr = n;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		len = ft_putnbr_rec(-nbr, len++);
	}
	else if (n > 9)
	{
		len = ft_putnbr_rec(nbr / 10, len);
		len = ft_putnbr_rec(nbr % 10, len);
	}
	else
		len += ft_putchar(nbr + '0');
	return (len);
}

size_t	ft_puthexa(ssize_t n, char format, size_t len)
{
	if (n > 15)
		len += ft_puthexa(n / 16, format, len);
	if (format == 'X')
		len += ft_putchar(HEX[n % 16]);
	else
		len += ft_putchar(hex[n % 16]);

	return (len);
}

size_t ft_putaddress(void *p, size_t len)
{
	char	*address_prefix;

	address_prefix = ft_strdup("0x");
	ft_putstr(address_prefix);
	len += ft_puthexa((ssize_t)p, 'x', len);
	return (len + ft_strlen(address_prefix));
}


size_t	ft_putstr_printf(void *s)
{
	char *str;

	str = (char *)s;
	if ( !str)
		str = ft_strdup("(null)");
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

size_t printer(char const *container, va_list args)
{
	if (ft_strchr("di", *container))
		return (ft_putnbr_rec(va_arg(args, int), 0));
	if (ft_strchr("xX", *container))
		return ft_puthexa(va_arg(args, size_t), *container, 0);
	if (*container == 'p')
		return ft_putaddress(va_arg(args, void *), 0);
	if (*container == 'u')
		return ft_uint_putnbr(va_arg(args, unsigned int));
	if (*container == 's')
		return ft_putstr_printf(va_arg(args, void *));
	if (*container == 'c')
		return ft_putchar(va_arg(args, int));
	if (*container == '%' )
		return ft_putchar(*container);
	return (0);
}

ssize_t	ft_printf(char const *container, ...)
{
	va_list	args;
	size_t	len;

	va_start(args, container);
	len = 0;
	while (*container)
	{
		if (*container == '%')
			len += printer(++container, args);
		else
			len += ft_putchar(*container);
		container++;
	}
	return (len);
}

int	main(void)
{
	void *d;

	printf("============\n");
	size_t len_mine = ft_printf("%s: %d%%\nThis is a null line: %s\nThis is an address: %p\n", "print my nummber", 42, NULL, &d);
	printf("============\n");
	size_t len_orig = printf("%s: %d%%\nThis is a null line: %s\nThis is an address: %p\n", "print my nummber", 42, "(null)", &d);
	printf("============\n");
	ft_printf("my hexa: %x\n", 1234);
	printf("system hexa: %x\n", 1234);
	ft_printf("my hexa: %X\n", 1514);
	printf("system hexa: %X\n", 1514);

	printf("len mine: %zu\nlen orig: %zu\n", len_mine, len_orig);
	return (0);
}