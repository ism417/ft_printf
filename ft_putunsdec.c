/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:35:39 by eismail           #+#    #+#             */
/*   Updated: 2024/01/03 16:46:46 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

int	ft_putunsdec(unsigned int nb, char *base)
{
	int				count;
	int				res;
	unsigned int	len_base;

	count = 0;
	res = 0;
	len_base = ft_strlen(base);
	if (nb < len_base)
	{
		count = ft_putchr(*(base + nb));
		if (count == -1)
			return (-1);
		return (count);
	}
	else
	{
		count = ft_putunsdec(nb / len_base, base);
		if (count == -1)
			return (-1);
		res = ft_putunsdec(nb % len_base, base);
		if (res == -1)
			return (-1);
		return (count + res);
	}
}
