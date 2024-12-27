/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:01:59 by qhatahet          #+#    #+#             */
/*   Updated: 2024/09/23 19:55:11 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_unsignednb(unsigned int U)
{
	char	c[10];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (U == 0)
		count += ft_putchar('0');
	while (U > 0)
	{
		c[i++] = U % 10 + '0';
		U /= 10;
	}
	while (i-- > 0)
		count += ft_putchar(c[i]);
	return (count);
}
