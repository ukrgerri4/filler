/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:16:48 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:30:13 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_lim(t_flist *lst, t_start cord)
{
	lst->x[0] = cord.x_plr;
	lst->y[0] = lst->width;
	lst->x[1] = lst->height;
	lst->y[1] = lst->width / 3;
	lst->place = 1;
}

void	second_lim(t_flist *lst, t_start cord)
{
	lst->x[0] = 0;
	lst->y[0] = lst->height / 3;
	lst->x[1] = cord.x_plr;
	lst->y[1] = lst->height;
	lst->place = 2;
}

void	find_limit_coordinates(t_flist *lst, t_start cord)
{
	if ((cord.x_plr - cord.x_foe) <= 0 && (cord.y_plr - cord.y_foe) < 0)
		first_lim(lst, cord);
	else if ((cord.x_plr - cord.x_foe) >= 0 && (cord.y_plr - cord.y_foe) < 0)
		second_lim(lst, cord);
	else if ((cord.x_plr - cord.x_foe) < 0 && (cord.y_plr - cord.y_foe) >= 0)
	{
		lst->x[0] = cord.x_plr;
		lst->y[0] = 0;
		lst->x[1] = lst->width;
		lst->y[1] = lst->height - lst->height / 3;
		lst->place = 3;
	}
	else
	{
		lst->x[0] = 0;
		lst->y[0] = lst->width - lst->width / 3;
		lst->x[1] = cord.x_plr;
		lst->y[1] = 0;
		lst->place = 4;
	}
	lst->flag++;
}

void	find_plr_place(t_flist *lst)
{
	t_start	cord;
	int		x;
	int		y;

	x = 0;
	while (x != lst->height)
	{
		y = 0;
		while (y != lst->width)
		{
			if (lst->map[x][y] == 2)
			{
				cord.x_plr = x;
				cord.y_plr = y;
			}
			if (lst->map[x][y] == 4)
			{
				cord.x_foe = x;
				cord.y_foe = y;
			}
			y++;
		}
		x++;
	}
	find_limit_coordinates(lst, cord);
}
