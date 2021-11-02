/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:12:54 by snarain           #+#    #+#             */
/*   Updated: 2021/05/11 18:45:35 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst2;

	lst2 = (t_list *)malloc(sizeof(t_list));
	if (!lst2)
		return (NULL);
	lst2->content = content;
	lst2->next = NULL;
	return (lst2);
}
