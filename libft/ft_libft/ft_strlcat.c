/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:50:20 by aessaoud          #+#    #+#             */
/*   Updated: 2023/06/06 13:57:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	res;
	size_t	i;

	dst_size = 0;
	src_size = 0;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[dst_size])
		dst_size++;
	while (src[src_size])
		src_size++;
	if (dst_size > dstsize)
		return (src_size + dstsize);
	res = dst_size + src_size;
	while (src[i] && dst_size < dstsize - 1)
	{
		dst[dst_size] = src[i];
		i++;
		dst_size++;
	}
	dst[dst_size] = '\0';
	return (res);
}
