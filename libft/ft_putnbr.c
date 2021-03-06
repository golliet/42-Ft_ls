/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:30:31 by golliet           #+#    #+#             */
/*   Updated: 2017/11/13 15:19:26 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int h;

	h = n;
	if (n < 0)
	{
		ft_putchar('-');
		h = -h;
	}
	if (h >= 10)
	{
		ft_putnbr(h / 10);
		ft_putchar(h % 10 + 48);
	}
	else
		ft_putchar(h + '0');
}
