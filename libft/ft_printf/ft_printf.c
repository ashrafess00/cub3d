/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:48:36 by aessaoud          #+#    #+#             */
/*   Updated: 2023/04/23 15:24:25 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(unsigned char c, va_list ptr)
{
	int		count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ptr, unsigned int));
	else if (c == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ptr, int), "0123456789");
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_putnbru(va_arg(ptr, unsigned long int), "0123456789abcdef");
	}
	else if (c == 'u')
		count += ft_putnbru(va_arg(ptr, unsigned int), "0123456789");
	else if (c == 'x')
		count += ft_putnbru(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbru(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ptr;

	va_start(ptr, s);
	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
			count += check_char(s[++i], ptr);
		else
			count += ft_putchar(s[i]);
	}
	va_end(ptr);
	return (count);
}
