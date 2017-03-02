/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:01:00 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 17:08:32 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		index;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (!tmp)
		return (NULL);
	i = 0;
	index = 0;
	while (*s)
		tmp[i++] = f(index++, *(s++));
	return (tmp);
}
