/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:19:26 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/18 20:48:22 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	len;
	char	*out;

	if (!s)
		return (NULL);
	idx = 0;
	len = ft_strlen(s) + 1;
	out = (char *)malloc(len * sizeof(char));
	if (!out)
		return (NULL);
	while (s[idx])
	{
		out[idx] = f(idx, s[idx]);
		idx++;
	}
	out[idx] = 0;
	return (out);
}
