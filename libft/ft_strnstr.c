/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:37:29 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/03 20:23:34 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*tmp_b;
	char	*tmp_l;
	int		buf_len;
	int		i;

	i = len;
	if (*little == 0)
		return ((char*)big);
	while (*big && i >= 0)
	{
		tmp_b = (char*)big;
		tmp_l = (char*)little;
		buf_len = i;
		while (*big && *little && *big == *tmp_l && i > 0)
		{
			big++;
			tmp_l++;
			i--;
		}
		if (*tmp_l == 0)
			return (tmp_b);
		i = buf_len - 1;
		big = tmp_b + 1;
	}
	return (0);
}
