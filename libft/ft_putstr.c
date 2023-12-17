/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:14:58 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/17 22:40:17 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char *s)
{
	if ( !s)
		s = ft_strdup("(null)");
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
