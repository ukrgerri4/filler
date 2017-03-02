/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:26:04 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 17:14:07 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	tmp = ft_strnew(len);
	if (!tmp)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		tmp[i++] = s[start++];
		len--;
	}
	tmp[i] = 0;
	return (tmp);
}
