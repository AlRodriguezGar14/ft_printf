/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:16:45 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/18 20:48:22 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	idx;

	if (!s)
		return ;
	idx = 0;
	while (*s)
		f(idx++, s++);
}
