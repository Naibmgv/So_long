/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:58:33 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/05 10:46:45 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_puthex(unsigned long long nb, int uppercase)
{
	int		count;
	char	*str;

	if (uppercase)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, uppercase);
	count += ft_putchar(str[nb % 16]);
	return (count);
}
