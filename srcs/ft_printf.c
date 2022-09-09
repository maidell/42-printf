/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:29:19 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/09/09 18:33:34 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(const char *str)
{
	char	text;
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] == '%') && (str[i + 1] == 'c'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 's'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 'p'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 'd'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 'i'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 'u'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 'x'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == 'X'))
			i++;
		else if ((str[i] == '%') && (str[i + 1] == '%'))
		{
			ft_putchar('%');
			i++;
		}
		else
		{
			text = str[i];
			ft_putchar(text);
		}
		i++;
	}
}

int	main(void)
{
	format("um %% dois");
}