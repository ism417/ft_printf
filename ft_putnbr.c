/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:39:53 by eismail           #+#    #+#             */
/*   Updated: 2024/01/03 16:43:26 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, char *base)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	if (n < 0)
	{
		count = ft_putchr('-');
		if (count == -1)
			return (-1);
		count = ft_putunsdec(-n, base);
		if (count == -1)
			return (-1);
		return (count + 1);
	}
	else
	{
		count = ft_putunsdec(n, base);
		if (count == -1)
			return (-1);
		return (count);
	}
}
