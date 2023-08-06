/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:05:07 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	int		i;
	char	*new_str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = -1;
	new_str = malloc(s_len + 1);
	if (new_str == NULL)
		return (0);
	while (s[++i])
		new_str[i] = f(i, s[i]);
	new_str[i] = '\0';
	return (new_str);
}
