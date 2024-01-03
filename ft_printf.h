/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:15:39 by eismail           #+#    #+#             */
/*   Updated: 2024/01/03 16:39:06 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const	char *parag, ...);
int	ft_putnbr(long n, char *base);
int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_puthexa(unsigned long nbr, char *base);
int	ft_putunsdec(unsigned int nb, char *base);

#endif