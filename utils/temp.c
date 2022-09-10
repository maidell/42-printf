static int	find_size(unsigned long long int number)
{
	int	lenght;

	lenght = 1;
	while (number >= 16)
	{
		lenght++;
		number = number / 16;
	}
	return (lenght);
}

static char	to_ascii(unsigned long int src, char flag)
{
	if (src <= 9)
		return (src + 48);
	else if (flag == 'x' || flag == 'p')
		return (src + 87);
	else if (flag == 'X')
		return (src + 55);
	return ('\0');
}

int	ft_puthex(unsigned int number, char flag)
{
	char				*str;
	int					size;
	unsigned long int	hex;

	size = find_size(number);
	if (flag == 'p')
	{
		if (!number)
			return (ft_printf("(nil)") - 2);
		ft_printf("0x");
	}
	if (number == 0)
		return (ft_printf("0"));
	str = calloc(sizeof(char), (size + 1));
	while (number != 0)
	{
		hex = (number % 16);
		str[--size] = to_ascii(hex, flag);
		number = number / 16;
	}
	size = ft_printf("%s", str);
	free (str);
	return (size);
}