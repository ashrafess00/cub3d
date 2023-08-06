/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:15:13 by aessaoud          #+#    #+#             */
/*   Updated: 2023/06/06 13:57:09 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_base(char *base)
{
	int	count;

	count = 0;
	while (base[count])
		count++;
	return (count);
}

static int	ft_print_base(unsigned long int num, char *base, long base_len)
{
	int	mod;
	int	count;

	count = 0;
	if (num != 0)
	{
		count += ft_print_base(num / base_len, base, base_len);
		mod = num % base_len;
		ft_putchar(base[mod]);
	}
	return (count + 1);
}

int	ft_putnbru(unsigned long int num, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = calc_base(base);
	if (num == 0)
		count = ft_putchar(base[0]) + 1;
	else
		count += ft_print_base(num, base, base_len);
	return (count - 1);
}
