/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:29:19 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/09/10 02:34:19 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(const char *str, va_list type)
{
	int	i;

	i = 0;
	if (str[i] == 'c')
		return (ft_putchar(va_arg(type, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(type, char *)));
	else if (str[i] == 'p')
		return (ft_puthex(va_arg(type, unsigned long int), 'p') + 2);
	else if ((str[i] == 'd') || (str[i] == 'i'))
		return (ft_putnbr(va_arg(type, int)));
	else if (str[i] == 'u')
		return (ft_putnbr(va_arg(type, unsigned int)));
	else if (str[i] == 'x')
		return (ft_puthex(va_arg(type, unsigned int), 'x'));
	else if (str[i] == 'X')
		return (ft_puthex(va_arg(type, unsigned int), 'X'));
	else if (str[i] == '%')
		return (ft_putchar('%'));

	return (0);

}

int	ft_printf(const char *printer, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, printer);
	while (*printer != 0)
	{
		if (*printer == '%')
		{
			printer++;
			i += format(printer, ap);
		}
		else
		{
			ft_putchar(*printer);
			i++;
		}
		printer++;
	}
	return (i);
}
