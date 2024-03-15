/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:16:57 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 11:52:43 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_con_hex(unsigned int n, char c, int len)
{
	if (c == 'x')
	{
		if (ft_putchar_p("0123456789abcdef"[n % 16]) < 0)
			return (-1);
		len++;
	}
	else if (c == 'X')
	{
		if (ft_putchar_p("0123456789ABCDEF"[n % 16]) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, char c)
{
	int	len;
	int	temp;

	len = 0;
	temp = 0;
	if (n == 0)
	{
		if (ft_putchar_p('0') < 0)
			return (-1);
		return (1);
	}
	else
	{
		if (n > 15)
		{
			temp = ft_puthex(n / 16, c);
			if (temp < 0)
				return (-1);
			len += temp;
		}
		len = ft_con_hex(n, c, len);
	}
	return (len);
}
