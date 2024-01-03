/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:39:59 by eismail           #+#    #+#             */
/*   Updated: 2024/01/03 16:44:28 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s != '\0')
	{
		res = ft_putchr((int)*s);
		if (res == -1)
			return (-1);
		count += res;
		s++;
	}
	return (count);
}
