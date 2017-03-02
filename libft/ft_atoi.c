/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:58:51 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/06 16:12:32 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int sign;

	sign = 1;
	nb = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\v' ||
				*str == '\f' || *str == '\r' || *str == '\n'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}
