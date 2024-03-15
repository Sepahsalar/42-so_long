/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:45:45 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 11:53:02 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(void *ptr)
{
	unsigned long	result;
	int				len;
	int				temp;

	temp = 0;
	result = (unsigned long)ptr;
	len = 0;
	if (result > 15)
	{
		temp = ft_putpoint((void *)(result / 16));
		if (temp < 0)
			return (-1);
		len += temp;
	}
	if (ft_putchar_p("0123456789abcdef"[result % 16]) < 0)
		return (-1);
	len++;
	return (len);
}
