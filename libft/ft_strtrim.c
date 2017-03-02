/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:54:19 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/11 16:09:38 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		len = 0;
	else
	{
		start = i;
		while (s[i])
			i++;
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		end = i;
		len = end - start + 1;
	}
	return (ft_strsub(s, start, len));
}
