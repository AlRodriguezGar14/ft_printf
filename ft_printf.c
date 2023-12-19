#include <stdarg.h>
#include "ft_printf.h"

# define hex "0123456789abcdef"
# define HEX "0123456789ABCDEF"

// size_t  ft_putnbr_rec(int n, size_t len)
// {
//     long nbr;

//     nbr = (long)n;
//     if (nbr < 0)
//     {
//         len += ft_putchar('-');
//         nbr = -nbr;
//     }
//     if (nbr > 9)
//         len = ft_putnbr_rec(nbr / 10, len);
//     len += ft_putchar((nbr % 10) + '0');
//     return (len);
// }


size_t	ft_puthexa(size_t n, char format, size_t len)
{
	if (n > 15)
		len += ft_puthexa(n / 16, format, len);
	if (format == 'X')
		ft_putchar(HEX[n % 16]);
	else
		ft_putchar(hex[n % 16]);
	len++;
	return (len);
}

size_t ft_putaddress(unsigned long p, size_t len)
{
	write(1, "0x", 2);
	len += ft_puthexa((unsigned long)p, 'x', len);
	return (len + 2);
}


size_t	ft_putstr_printf(char *s)
{
	if ( !s)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t printer(char const *container, va_list *args)
{
	if (ft_strchr("di", *container))
		return ft_putnbr_fd(va_arg(*args, int), 1);
	if (ft_strchr("xX", *container))
		return ft_puthexa(va_arg(*args, size_t), *container, 0);
	if (*container == 'p')
		return ft_putaddress(va_arg(*args, unsigned long), 0);
	if (*container == 'u')
		return ft_uint_putnbr(va_arg(*args, unsigned int));
	if (*container == 's')
		return ft_putstr_printf(va_arg(*args, void *));
	if (*container == 'c')
		return ft_putchar(va_arg(*args, int));
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
			len += printer(++container, &args);
		else
			len += ft_putchar(*container);
		container++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("hi mom, %s", "bye mom");
// 	return (0);
// }
