/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:25:11 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 11:51:25 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_cal(char *result, int count, int nbr)
{
	int	i;
	int	n;
	int	temp;

	n = nbr;
	i = count - 1;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	if (n < 0)
		temp = 1;
	else
		temp = 0;
	while (i >= temp)
	{
		result[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	result[count] = '\0';
	return (result);
}

static char	*ft_itoa_p(int n)
{
	char	*result;
	int		count;
	int		nbr;

	nbr = n;
	count = 0;
	if (n == 0)
		return (ft_strdup_p("0"));
	if (n == -2147483648)
		return (ft_strdup_p("-2147483648"));
	if (n < 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	result = (char *)malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	return (ft_cal(result, count, nbr));
}

int	ft_putnbr_p(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa_p(n);
	if (!num)
		return (-1);
	len = ft_putstr_p(num);
	free(num);
	return (len);
}
