/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:08:28 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:12:05 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct	s_flist
{
	int		height;
	int		width;
	int		**map;
	int		flag;
	int		order;
	char	plr[2];
	char	foe[2];
	int		x[2];
	int		y[2];
	int		place;
	int		min_dist;
	int		bestx;
	int		besty;
}				t_flist;

typedef struct	s_figure
{
	int				x;
	int				y;
	int				f;
	struct s_figure	*next;
}				t_figure;

typedef struct	s_start
{
	int	x_plr;
	int	y_plr;
	int	x_foe;
	int	y_foe;
}				t_start;

void			check_player(char *line, t_flist *lst);
char			*check_mapsize(char *line, t_flist *lst);
void			check_figure(char *line, t_figure **fgr);
void			find_place(t_flist *lst, t_figure *fgr);
void			ft_fgr_delete(t_figure **fgr);
void			find_limit_coordinates(t_flist *lst, t_start cord);
void			find_plr_place(t_flist *lst);
int				mod(int a, int y);

void			best_place_1(t_flist *lst, t_figure *fgr, int x, int y);
void			best_place_2(t_flist *lst, t_figure *fgr, int x, int y);
void			best_place_3(t_flist *lst, t_figure *fgr, int x, int y);
void			best_place_4(t_flist *lst, t_figure *fgr, int x, int y);

#endif
