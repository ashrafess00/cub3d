/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:22:45 by aessaoud          #+#    #+#             */
/*   Updated: 2023/05/22 20:17:28 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	pdst = (char *) dst;
	psrc = (char *) src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*(pdst + i) = *(psrc + i);
		i++;
	}
	return (dst);
}
