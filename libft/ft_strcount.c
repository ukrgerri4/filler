/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:05:44 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/06 16:11:27 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(char *s)
{
	size_t count;

	count = 0;
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				count++;
			s++;
		}
	}
	else
		return (count);
	return (count);
}
