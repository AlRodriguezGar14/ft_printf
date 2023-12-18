/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:11:17 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/18 20:48:22 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*content;

	idx = -1;
	content = str;
	while (++idx < n)
	{
		if (*content == (unsigned char)c)
			return ((void *)content);
		content++;
	}
	return (NULL);
}
