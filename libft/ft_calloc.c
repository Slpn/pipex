/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:04:32 by snarain           #+#    #+#             */
/*   Updated: 2021/03/26 15:04:34 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*memo;

	len = nmemb * size;
	memo = malloc(len);
	if (memo == NULL)
		return (NULL);
	ft_bzero(memo, len);
	return (memo);
}
