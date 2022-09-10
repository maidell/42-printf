/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:24:06 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/09/10 06:45:42 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{	
	int	count_size;

	count_size = 0;
	if (!s)
	{
		ft_printf("(null)");
		return (6);
	}
	while (s[count_size] != '\0')
	{
		write (1, &s[count_size], 1);
		count_size++;
	}
	return (count_size);
}
