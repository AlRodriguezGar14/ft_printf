#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define hex "0123456789abcdef"
#define HEX "0123456789ABCDEF"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (const unsigned char *)src;
	while (n--)
		*char_dest++ = *char_src++;
	return (dest);
}

void	*ft_memset(void *buffer, int val, size_t len)
{
	unsigned char	*p;

	p = buffer;
	while (len--)
		*p++ = (unsigned char)val;
	return (buffer);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

static int	get_simbol(long n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static int	get_len(unsigned long num, int simbol)
{
	int	len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len + (simbol < 0 ? 1 : 0));
}

char	*ft_itoa_long(long n)
{
	char			*charnum;
	int				len;
	int				simbol;
	unsigned long	num;

	num = (unsigned long)(n < 0 ? -n : n);
	simbol = get_simbol(n);
	len = get_len(num, simbol);
	charnum = malloc(len + 1);
	if (!charnum)
		return (NULL);
	charnum[len] = '\0';
	if (simbol < 0)
		charnum[0] = '-';
	while (len-- > (simbol < 0 ? 1 : 0))
	{
		charnum[len] = (num % 10) + '0';
		num /= 10;
	}
	return (charnum);
}

char	*ft_puthexa_str(size_t n, char format)
{
	static char	buffer[17];
	char		*hexa;
	int			i;
	char		*res;

	ft_memset(buffer, '0', sizeof(buffer));
	hexa = (format == 'X') ? HEX : hex;
	i = 15;
	while (n > 0)
	{
		buffer[i] = hexa[n % 16];
		n /= 16;
		i--;
	}
	res = strdup(&buffer[i + 1]);
	return (res);
}

char	*ft_putaddress_str(unsigned long p, char format)
{
	static char	buffer[19];
	char		*hexa;
	int			i;
	char		*res;

	ft_memset(buffer, '0', sizeof(buffer));
	hexa = (format == 'X') ? HEX : hex;
	i = 17;
	buffer[0] = '0';
	buffer[1] = 'x';
	while (p > 0)
	{
		buffer[i] = hexa[p % 16];
		p /= 16;
		i--;
	}
	res = strdup(&buffer[i + 1]);
	return (res);
}

char	*printer(char const *container, va_list *args)
{
	char	*res;

	if (ft_strchr("di", *container))
		return (ft_itoa_long(va_arg(*args, int)));
	if (ft_strchr("xX", *container))
		return (ft_puthexa_str(va_arg(*args, size_t), *container));
	if (*container == 'p')
		return (ft_putaddress_str(va_arg(*args, unsigned long), *container));
	if (*container == 'u')
		return (ft_itoa_long(va_arg(*args, unsigned int)));
	if (*container == 's')
	{
		res = strdup(va_arg(*args, char *));
		return (res);
	}
	if (*container == 'c')
	{
		res = malloc(2);
		res[0] = (char)va_arg(*args, int);
		res[1] = '\0';
		return (res);
	}
	if (*container == '%')
	{
		res = strdup("%");
		return (res);
	}
	return (0);
}

char	*allocate_and_copy(char *old_result, char *tmp, int old_len,
		char container)
{
	char	*result;

	result = malloc(old_len + strlen(tmp) + 1);
	ft_memcpy(result, old_result, old_len);
	ft_memcpy(result + old_len, tmp, strlen(tmp));
	result[old_len + strlen(tmp)] = '\0';
	free(old_result);
	free(tmp);
	return (result);
}

char	*handle_percent_case(char const **container, va_list *args,
		char *result)
{
	char	*tmp;
	int		old_len;

	tmp = printer(++(*container), args);
	old_len = strlen(result);
	result = allocate_and_copy(result, tmp, old_len, **container);
	return (result);
}

char	*handle_normal_case(char const **container, char *result)
{
	char	*tmp;
	int		old_len;

	tmp = malloc(2);
	tmp[0] = **container;
	tmp[1] = '\0';
	old_len = strlen(result);
	result = allocate_and_copy(result, tmp, old_len, **container);
	return (result);
}

char	*ft_sprintf(char const *container, ...)
{
	va_list	args;
	char	*result;

	va_start(args, container);
	result = malloc(sizeof(char));
	*result = '\0';
	while (*container)
	{
		if (*container == '%')
			result = handle_percent_case(&container, &args, result);
		else
			result = handle_normal_case(&container, result);
		container++;
	}
	va_end(args);
	return (result);
}

int	main(void)
{
	char *out = ft_sprintf("working:? %s\n", "yes");
	printf("%s", out);
	return (0);
}