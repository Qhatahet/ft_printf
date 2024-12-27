/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:17:41 by qhatahet          #+#    #+#             */
/*   Updated: 2024/09/23 19:56:33 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_tohex(unsigned int value, char type)
{
	char	*s;
	int		count;

	count = 0;
	if (type == 'x')
		s = "0123456789abcdef";
	else if (type == 'X')
		s = "0123456789ABCDEF";
	if (value >= 16)
	{
		count += ft_tohex(value / 16, type);
		count += ft_putchar(s[value % 16]);
	}
	else
		count += ft_putchar(s[value]);
	return (count);
}
