/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_top_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:25:42 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:26:06 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	mission_complete_0(t_flist *lst)
{
	int	x;

	x = 0;
	while (x != lst->height)
	{
		if (lst->map[x][lst->y[0]] == 2 ||
			lst->map[x][lst->y[0]] == 1 ||
			lst->map[x][lst->y[0] + 1] == 2 ||
			lst->map[x][lst->y[0] + 1] == 1)
			return (1);
		x++;
	}
	return (0);
}

static int	mission_complete_1(t_flist *lst)
{
	int	y;

	y = 0;
	while (y != lst->width)
	{
		if (lst->map[lst->x[1] - 1][y] == 2 ||
			lst->map[lst->x[1] - 1][y] == 1 ||
			lst->map[lst->x[1] - 2][y] == 2 ||
			lst->map[lst->x[1] - 2][y] == 1)
			return (1);
		y++;
	}
	return (0);
}

static void	help(t_flist *lst, int x, int y, int *dist)
{
	lst->bestx = x;
	lst->besty = y;
	lst->min_dist = *dist;
}

void		best_place_3(t_flist *lst, t_figure *fgr, int x, int y)
{
	int		dist;

	if (mission_complete_1(lst) || (((lst->order % 2) == 0 ||
		lst->order == 0) && !mission_complete_0(lst)))
		while (fgr)
		{
			if (fgr->f && (dist = (mod(x, lst->x[0]) +
				mod(y, lst->y[0]))) < lst->min_dist)
				help(lst, x, y, &dist);
			fgr = fgr->next;
		}
	else if ((lst->order % 2) != 0 && !mission_complete_1(lst))
		while (fgr)
		{
			if (fgr->f && (dist = (mod(x, lst->x[1]) +
				mod(y, lst->y[1]))) < lst->min_dist)
				help(lst, x, y, &dist);
			fgr = fgr->next;
		}
	else
	{
		lst->bestx = x;
		lst->besty = y;
	}
}
