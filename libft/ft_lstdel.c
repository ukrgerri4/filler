/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:19:29 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/03 22:49:40 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst)
	{
		if (*alst)
		{
			while (*alst)
			{
				tmp = (*alst)->next;
				del((*alst)->content, (*alst)->content_size);
				free(*alst);
				(*alst) = 0;
				(*alst) = tmp;
			}
		}
	}
	else
		return ;
}
