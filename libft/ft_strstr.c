/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:22:59 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 00:58:41 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *tmp_b;
	char *tmp_l;

	if (*little == 0)
		return ((char*)big);
	while (*big)
	{
		tmp_b = (char*)big;
		tmp_l = (char*)little;
		while (*big && *little && *big == *tmp_l)
		{
			big++;
			tmp_l++;
		}
		if (*tmp_l == 0)
			return (tmp_b);
		big = tmp_b + 1;
	}
	return (0);
}
