/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:23:57 by qhatahet          #+#    #+#             */
/*   Updated: 2024/09/23 20:12:27 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_ptr(unsigned long add)
{
	char	*s;
	int		count;

	count = 0;
	s = "0123456789abcdef";
	if (add == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (add >= 16)
	{
		count += ft_ptr(add / 16);
		count += ft_putchar(s[add % 16]);
	}
	else
		count += ft_putchar(s[add]);
	return (count);
}
