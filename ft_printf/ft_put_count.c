/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:42:44 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/05 13:21:57 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(int c)
{
	write(1, &c, 1);
	g_count++;
}

void	ft_putstr_count(char *s)
{
	if (s)
	{
		while (*s)
			ft_putchar_count(*(s++));
	}
}

char	*ft_itoa_base_s(ssize_t value, int base)
{
	int			i;
	ssize_t		n;
	char		*s;
	static char	hex[17] = "0123456789ABCDEF";

	i = (value < 0 && base == 10) ? 2 : 1;
	n = value;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	s[i] = 0;
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[(n < 0) ? -(n % base) : n % base];
		n /= base;
	}
	return (s);
}

char	*ft_itoa_base_us(size_t value, int base)
{
	int				i;
	size_t			n;
	char			*s;
	static char		hex[17] = "0123456789ABCDEF";

	i = 1;
	n = value;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	s[i] = 0;
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[n % base];
		n /= base;
	}
	return (s);
}

char	*ft_tolower_str(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] + 32;
			i++;
		}
		return (s);
	}
	return (NULL);
}
