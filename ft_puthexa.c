/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:17:09 by eismail           #+#    #+#             */
/*   Updated: 2024/01/03 16:43:13 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nbr, char *base)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	if (nbr < 16)
	{
		count = ft_putstr("0x");
		if (count == -1)
			return (-1);
		res = ft_putchr(base[nbr]);
		if (res == -1)
			return (-1);
		return (count + res);
	}
	else
	{
		count = ft_puthexa((nbr / 16), base);
		if (count == -1)
			return (-1);
		res = ft_putchr(base[nbr % 16]);
		if (res == -1)
			return (-1);
		return (count + res);
	}
}
