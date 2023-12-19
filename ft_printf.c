#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_nbr(long n, int base)
{
	int count = 0;

	char hex[16] = "0123456789abcdef";

	if (n < 0)
	{
		if (base == 10)
			count = print_char('-');
		n = -n;
	}
	if (n >= base)
		count += print_nbr(n / base, base);
	
	return (print_char(hex[n % base]));
}

int	print_content(char fmt, va_list *arg)
{
	int count = 0;

	if (fmt == 'c')
		return print_char(va_arg(*arg, int));
	if (fmt == 'd')
		return print_nbr((long)(va_arg(*arg, int)), 10);
	if (fmt == 'x')
		return print_nbr((long)(va_arg(*arg, unsigned int)), 16);
	else
		return write(1, &fmt, 1);
}


int	ft_printf(char* fmt, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			count += print_content(*(++fmt), &arg);
		else
			count += write(1, fmt, 1);
		++fmt;
	}
	va_end(arg);
	return (count);
}



int	main(void)
{
	ft_printf("%cbr = %d",'N', -69);
	ft_printf("\n");
	ft_printf("%cbr = %x",'N', -15);
	ft_printf("\n");
	printf("original: %x", -15);
	printf("\n");
	return (0);
}	
