/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:18:34 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/11 14:46:13 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (*((unsigned char*)src) != (unsigned char)c)
			n--;
		else
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
