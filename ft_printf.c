#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define MAX_UINT_LEN 12

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_nbr(long n, int base)
{
	int	count;
	int	idx;
    char hex[] = "0123456789abcdef";
	char	buffer[MAX_UINT_LEN];

	count = 0;
	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n == 0)
		return print_char('0');
	idx = 0;
	while (n > 0)
	{
		buffer[idx++] = hex[n % base];
		n /= base;
	}
	while (idx--)
		count += print_char(buffer[idx]);
	return (count);
}


int	print_content(char fmt, va_list *arg)
{
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
	int mine_len = ft_printf("p%cintf: %x - %d%%", 'l', -15, -15);
	ft_printf("\n");
	int original_len = printf("p%cintf: %x - %d%%",'r', -15, -15);
	printf("\nmy len: %d\noriginal len: %d", mine_len, original_len);
	printf("\n");
	return (0);
}	
