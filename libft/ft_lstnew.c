/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:06:11 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 20:31:06 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if ((tmp = malloc(sizeof(t_list))))
	{
		if (content)
		{
			tmp->content = ft_strsub(content, 0, content_size);
			if (!tmp->content)
				return (NULL);
			tmp->content_size = content_size;
		}
		else
		{
			tmp->content = 0;
			tmp->content_size = 0;
		}
		tmp->next = 0;
	}
	else
		return (NULL);
	return (tmp);
}
