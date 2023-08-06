/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:57:44 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by aessaoud         ###   ########.fr       */
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

static int	ft_print_base(long int num, char *base, long base_len)
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

int	ft_putnbr(long int num, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = calc_base(base);
	if (num < 0)
	{
		count = ft_putchar('-');
		num *= -1;
	}
	if (num == 0)
		count = ft_putchar(base[0]) + 1;
	else
		count += ft_print_base(num, base, base_len);
	return (count - 1);
}
