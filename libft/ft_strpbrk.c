/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:05:49 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/06 16:10:44 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str1, const char *str2)
{
	const char *tmp;

	tmp = str2;
	if (*str1 && *str2)
	{
		while (*str1)
		{
			str2 = tmp;
			while (*str2)
			{
				if (*str1 == *str2)
					return ((char*)str1);
				str2++;
			}
			str1++;
		}
	}
	return (NULL);
}
