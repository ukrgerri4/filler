/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:07:00 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:08:14 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initialize_lst(t_flist *lst)
{
	lst->flag = 0;
	lst->order = 0;
}

int		main(void)
{
	t_flist		lst;
	t_figure	*fgr;
	char		*line;

	fgr = 0;
	initialize_lst(&lst);
	while (get_next_line(0, &line))
	{
		if (line[0] == '$')
		{
			check_player(line, &lst);
			while (line[0] != 'P')
				get_next_line(0, &line);
		}
		if (line[0] == 'P' && ft_strstr(line, "Plateau"))
		{
			line = check_mapsize(line, &lst);
			if (!lst.flag)
				find_plr_place(&lst);
			check_figure(line, &fgr);
			find_place(&lst, fgr);
			ft_fgr_delete(&fgr);
		}
	}
	return (0);
}
