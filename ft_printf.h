/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:41:13 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/20 16:00:16 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_STDOUT 1
# define FD_STDERR 2
# define MAX_INT_LEN 12
# define MAX_LONG_LEN 22
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int	ft_printf(const char *fmt, ...);
int	ft_printstr(char *s);
int	ft_printnbr(long nbr, int base, char *nbr_formatter);
int	ft_print_addr(unsigned long nbr, int base, char *nbr_formatter);
int	ft_printchar(int c);

#endif
