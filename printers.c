/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 03:35:52 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/18 15:09:47 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t	ft_puthexa(int n, char format, size_t len)
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
	ft_putstr("0x1");
	len += ft_puthexa((ssize_t)p, 'x', 0);
	return (len + 3);
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