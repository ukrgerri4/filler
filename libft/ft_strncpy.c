/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:57:50 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/06 01:29:56 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (*src != '\0' && len > 0)
	{
		*tmp++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*tmp++ = '\0';
		--len;
	}
	return (dst);
}
