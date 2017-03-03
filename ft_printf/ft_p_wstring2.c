/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_wstring2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:57:50 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/07 15:58:05 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fix_prec(int d, wchar_t *str)
{
	int sum;
	int	i;

	sum = 0;
	while (*str)
	{
		if (*str >= 0x0 && *str <= 0x7F)
			i = 1;
		else if (*str >= 0x80 && *str <= 0x7FF)
			i = 2;
		else if (*str >= 0x800 && *str <= 0xFFFF)
			i = 3;
		else if (*str >= 0x10000 && *str <= 0x1FFFFF)
			i = 4;
		if (d < (sum + i))
			return (sum);
		sum += i;
		str++;
	}
	return (d);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	i;
	size_t	sum;

	sum = 0;
	while (*str)
	{
		if (*str >= 0x0 && *str <= 0x7F)
			i = 1;
		else if (*str >= 0x80 && *str <= 0x7FF)
			i = 2;
		else if (*str >= 0x800 && *str <= 0xFFFF)
			i = 3;
		else if (*str >= 0x10000 && *str <= 0x1FFFFF)
			i = 4;
		sum += i;
		str++;
	}
	return (sum);
}
