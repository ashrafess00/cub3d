/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:07:50 by aessaoud          #+#    #+#             */
/*   Updated: 2023/06/06 13:57:14 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	free((char *)s);
	return (p);
}
