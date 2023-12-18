#include "libftprintf.h"

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