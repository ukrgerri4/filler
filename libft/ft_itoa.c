/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:24:32 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/11 16:11:09 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_str(int n, int len, int capacity, int sign)
{
	char *str;
	char *tmp;

	if (n == -2147483648)
		return (str = ft_strsub("-2147483648", 0, sizeof("-2147483648")));
	if (n == 0)
		return (str = ft_strsub("0", 0, 1));
	else
		str = ft_strnew(len + sign);
	if (str)
	{
		tmp = str;
		if (sign == 1)
			*(str++) = '-';
		while (len > 0)
		{
			*(str++) = (n / capacity) + '0';
			n = n % capacity;
			capacity /= 10;
			len--;
		}
		*str = 0;
		return (tmp);
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	int len;
	int capacity;
	int buf;
	int sign;

	sign = 0;
	len = 0;
	capacity = 1;
	if (n == -2147483648 || n == 0)
		return (create_str(n, len, capacity, sign));
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	buf = n;
	while (buf)
	{
		buf = buf / 10;
		if (buf)
			capacity *= 10;
		len++;
	}
	return (create_str(n, len, capacity, sign));
}
