/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:44:08 by aessaoud          #+#    #+#             */
/*   Updated: 2023/06/06 13:56:27 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_chars(int n)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*create_string(long number, size_t chars_len, size_t is_neg)
{
	char		*number_string;
	size_t		i;
	int			l;

	i = 0;
	number_string = ft_calloc(chars_len + 1, sizeof(char));
	l = chars_len;
	if (number_string == NULL)
		return (0);
	if (is_neg)
	{
		if (number_string == NULL)
			return (0);
		number_string[0] = '-';
	}
	while (chars_len-- > is_neg)
	{
		number_string[chars_len] = (number % 10) + 48;
		number = number / 10;
	}
	return (number_string);
}

char	*ft_itoa(int n)
{
	size_t	chars_len;
	long	number;
	char	*p;

	number = n;
	if (n < 0)
	{
		chars_len = calc_chars(number * -1);
		p = create_string(number * -1, chars_len + 1, 1);
	}
	else if (n == 0)
	{
		p = ft_calloc(2, 1);
		p[0] = '0';
	}
	else
	{
		chars_len = calc_chars(number);
		p = create_string(number, chars_len, 0);
	}
	return (p);
}
