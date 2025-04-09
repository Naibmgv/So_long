/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:39 by event             #+#    #+#             */
/*   Updated: 2025/03/05 10:46:45 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_check(const char *s, va_list args, int i)
{
	int	count;

	count = 0;
	if (s[i + 1] == ' ')
		return (0);
	else if (s[i + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s[i + 1] == 's')
		count += (ft_putstr(va_arg(args, char *)));
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s[i + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (s[i + 1] == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (s[i + 1] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (s[i + 1] == 'p')
		count += (ft_putptr((unsigned long long)va_arg(args, void *)));
	else if (s[i + 1] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;

	size = 0;
	i = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			size += ft_check(s, args, i);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			size++;
		}
		i++;
	}
	va_end (args);
	return (size);
}
