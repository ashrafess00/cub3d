/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:21:20 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ws(char n)
{
	if (n == '\t' || n == '\n' || n == ' '
		|| n == '\v' || n == '\f' || n == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	sign;
	size_t	i;
	size_t	num;

	sign = 1;
	i = 0;
	num = 0;
	while (is_ws(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}
