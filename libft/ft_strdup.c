/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:50:13 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/11 15:56:27 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc((ft_strlen(str) + 1) * sizeof(*str));
	i = 0;
	if (tmp != 0)
	{
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = 0;
	}
	else
		return (0);
	return (tmp);
}
