/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:36:32 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 16:56:14 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*tmp;
	int				i;

	tmp = (unsigned char*)str;
	i = 0;
	if (len == 0)
		return (str);
	while (len-- > 0)
		tmp[i++] = (unsigned char)c;
	return (str);
}
