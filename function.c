/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:12:14 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:13:26 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_player(char *line, t_flist *lst)
{
	if (ft_strstr(line, "[my_players/filler]") && ft_strstr(line, "p1"))
	{
		lst->plr[0] = 'o';
		lst->plr[1] = 'O';
		lst->foe[0] = 'x';
		lst->foe[1] = 'X';
	}
	else
	{
		lst->plr[0] = 'x';
		lst->plr[1] = 'X';
		lst->foe[0] = 'o';
		lst->foe[1] = 'O';
	}
}

int		check_empty(char c, t_flist *lst)
{
	if (c == '.')
		return (0);
	else if (c == lst->plr[0])
		return (1);
	else if (c == lst->plr[1])
		return (2);
	else if (c == lst->foe[0])
		return (3);
	else if (c == lst->foe[1])
		return (4);
	return (0);
}

void	make_intarr(t_flist *lst)
{
	int	i;

	i = 0;
	lst->map = (int**)malloc(sizeof(*lst->map) * lst->height);
	while (i < lst->height)
		lst->map[i++] = (int*)malloc(sizeof(int) * lst->width);
}

void	check_map_param(char *line, t_flist *lst)
{
	int i;

	i = 0;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	lst->height = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	lst->width = ft_atoi(&line[i]);
}

char	*check_mapsize(char *line, t_flist *lst)
{
	int		x;
	int		y;
	char	*tmp;

	check_map_param(line, lst);
	make_intarr(lst);
	get_next_line(0, &line);
	x = 0;
	while (get_next_line(0, &line) && line[0] != 'P')
	{
		y = 0;
		tmp = &line[4];
		while (tmp[y] != '\0' && y != lst->width)
		{
			lst->map[x][y] = check_empty(tmp[y], lst);
			y++;
		}
		x++;
	}
	return (line);
}
