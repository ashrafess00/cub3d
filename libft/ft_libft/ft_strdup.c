/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:18:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/05/21 15:29:05 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	size_t	i;
	char	*new_str;

	i = 0;
	str_len = ft_strlen(s1);
	new_str = malloc(str_len + 1);
	if (new_str == NULL)
		return (0);
	while (i < str_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
