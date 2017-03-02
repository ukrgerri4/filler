/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 00:47:54 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/11 16:43:06 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*split_c_from_start(const char *s, char c)
{
	const char *tmp;

	if (s)
	{
		tmp = s;
		while (*tmp == c)
			tmp++;
		return (tmp);
	}
	else
		return (NULL);
}

static int			count_words(const char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		i++;
		s = split_c_from_start(s, c);
	}
	return (i);
}

static char			**make_arr(const char *s, char c)
{
	char		**arr;
	const char	*tmp;
	int			i;
	int			j;

	j = 0;
	arr = ft_memalloc(sizeof(arr) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		tmp = s;
		i = 0;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		if (!(arr[j++] = ft_strsub(tmp, 0, i)))
			return (NULL);
		if (*s)
			s = split_c_from_start(s, c);
	}
	arr[j] = 0;
	return (arr);
}

char				**ft_strsplit(char const *s, char c)
{
	if (s && c)
		s = split_c_from_start(s, c);
	else
		return (NULL);
	return (make_arr(s, c));
}
