/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:23 by qhatahet          #+#    #+#             */
/*   Updated: 2024/09/23 20:17:54 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

static void	check(char ch, va_list q, int *count)
{
	unsigned long	pt;

	if (ch == 'p')
	{
		pt = va_arg(q, unsigned long);
		if (pt != 0)
			(*count) += write (1, "0x", 2);
		(*count) += ft_ptr(pt);
	}
	else if (ch == 'c')
		(*count) += ft_putchar(va_arg(q, int));
	else if (ch == 's')
		(*count) += ft_putstr(va_arg(q, char *));
	else if (ch == '%')
		(*count) += ft_putchar('%');
	else if (ch == 'i' || ch == 'd')
		(*count) += ft_putnbr(va_arg(q, int));
	else if (ch == 'u')
		(*count) += ft_unsignednb(va_arg(q, unsigned int));
	else if (ch == 'x' || ch == 'X')
		(*count) += ft_tohex(va_arg(q, unsigned long), ch);
}

int	ft_printf(const char *p, ...)
{
	va_list	q;
	int		count;

	count = 0;
	va_start(q, p);
	while (*p != '\0')
	{
		if (*p != '%' && p)
			count += write(1, p, 1);
		else if (*p == '%' && p)
		{
			p++;
			check(*p, q, &count);
		}
		p++;
	}
	va_end(q);
	return (count);
}
/*
int	main(void)
{
	int d= 45;
	ft_printf("%p",&d);
	printf("\n");
	//printf("char %p", 0);
	return (0);
}*/
