/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:42:55 by alberrod          #+#    #+#             */
/*   Updated: 2023/12/18 20:48:22 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_l;

	new_l = malloc(sizeof(struct s_list));
	if (!new_l)
		return (NULL);
	new_l->content = content;
	new_l->next = NULL;
	return (new_l);
}
