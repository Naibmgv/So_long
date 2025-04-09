/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:01:00 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/05 10:46:45 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	char	b;
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	b = (nb % 10) + '0';
	count += write(1, &b, 1);
	return (count);
}
