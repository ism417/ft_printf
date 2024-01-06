/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:17:11 by eismail           #+#    #+#             */
/*   Updated: 2024/01/06 13:25:40 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	ft_type(const char *sp, va_list ap)
{
	int	count;

	count = 0;
	if (*sp == 'c')
		count = ft_putchr(va_arg(ap, int));
	else if (*sp == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (*sp == 'd' || *sp == 'i')
		count = ft_putnbr((long)va_arg(ap, int), "0123456789");
	else if (*sp == 'u')
		count = ft_putunsdec((unsigned int)va_arg(ap, int), "0123456789");
	else if (*sp == 'x')
		count = ft_putnbr((long)va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*sp == 'p')
	{
		count = ft_puthexa((unsigned long)va_arg(ap, void *),
				"0123456789abcdef");
	}
	else if (*sp == 'X')
		count = ft_putnbr((long)va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*sp == '%')
		count = ft_putchr('%');
	else
		count = ft_putchr(*(int *)sp);
	return (count);
}

static	int	ft_cheak(const char *ptr, va_list ap)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			res = ft_type((++ptr), ap);
			if (res == -1)
				return (-1);
			count += res;
		}
		else
		{
			res = write (1, ptr, 1);
			if (res == -1)
				return (-1);
			count += res;
		}
		ptr++;
	}
	return (count);
}

int	ft_printf(const char *parag, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, parag);
	count = ft_cheak(parag, ap);
	va_end(ap);
	if (count == -1)
		return (-1);
	return (count);
}
