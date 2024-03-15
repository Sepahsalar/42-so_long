/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:30 by asohrabi          #+#    #+#             */
/*   Updated: 2024/03/15 11:51:31 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_strlen_p(char *s);
int		ft_putchar_p(int c);
int		ft_putstr_p(char *s);
char	*ft_strchr_p(char *s, int c);
char	*ft_strdup_p(char *src);
int		ft_putnbr_p(int n);
int		ft_uns_putnbr(unsigned int n);
int		ft_putpoint(void *ptr);
int		ft_puthex(unsigned int n, char c);

#endif