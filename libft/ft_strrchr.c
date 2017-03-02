/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:00:48 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 17:13:26 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	b;
	char	*tmp;
	int		flag;

	b = '\0' + c;
	if (b == '\0')
	{
		while (*str)
			str++;
		return ((char*)str);
	}
	tmp = (char*)str;
	flag = 0;
	while (*str)
	{
		if (*str == b)
		{
			tmp = (char*)str;
			flag = 1;
		}
		str++;
	}
	if (flag == 0)
		return (0);
	return (tmp);
}
