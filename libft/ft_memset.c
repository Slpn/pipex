/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:06:23 by snarain           #+#    #+#             */
/*   Updated: 2021/03/26 15:06:24 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		a;

	if (!b)
		return (NULL);
	a = 0;
	while (a < len)
	{
		*(unsigned char *)(b + a) = (unsigned char)c;
		a++ ;
	}
	return (b);
}
