#include "filler.h"

int		mod(int a, int y)
{
    int val;
    
    val = 0;
    if (a - y < 0)
        val = (a - y) * -1;
    else
        val = (a - y);
    return (val);
}

void	check_best_plase_up(t_flist *lst, t_figure *fgr, int x, int y)
{
	int		dist;

	if ((lst->order % 3) == 0 && lst->order != 0)
		while(fgr)
		{
			if (fgr->f && (dist = (mod(x, lst->x[0]) + mod(y, lst->y[0]))) < lst->min_dist)
			{
				lst->bestx = x;
				lst->besty = y;
				lst->min_dist = dist;
			}
			fgr = fgr->next;
		}
	else
		while(fgr)
		{
			if (fgr->f && (dist = (mod(x, lst->x[1]) + mod(y, lst->y[1]))) < lst->min_dist)
			{
				lst->bestx = x;
				lst->besty = y;
				lst->min_dist = dist;
			}
			fgr = fgr->next;
		}
}

void	check_best_plase_down(t_flist *lst, t_figure *fgr, int x, int y)
{
	int		dist;

	if ((lst->order % 3) == 0 && lst->order != 0)
		while(fgr)
		{
			if (fgr->f && (dist = (mod(x, lst->x[1]) + mod(y, lst->y[1]))) < lst->min_dist)
			{
				lst->bestx = x;
				lst->besty = y;
				lst->min_dist = dist;
			}
			fgr = fgr->next;
		}
	else
		while(fgr)
		{
			if (fgr->f && (dist = (mod(x, lst->x[0]) + mod(y, lst->y[0]))) < lst->min_dist)
			{
				lst->bestx = x;
				lst->besty = y;
				lst->min_dist = dist;
			}
			fgr = fgr->next;
		}
}

void	check_best_plase(t_flist *lst, t_figure *fgr, int x, int y)
{
	if (lst->y[1] == (lst->width / 2))
		check_best_plase_up(lst, fgr, x, y);
	else
		check_best_plase_down(lst, fgr, x, y);
}

int		check_valid_place(t_flist *lst, t_figure *fgr, int x, int y)
{
	int flag;

	flag = 0;
	while (fgr)
	{
		if ((fgr->x + x) >= lst->height || (fgr->y + y) >= lst->width)
			return (0);
		if (fgr->f)
			if (lst->map[fgr->x + x][fgr->y + y] == 3 || lst->map[fgr->x + x][fgr->y + y] == 4)
				return (0);
		if (fgr->f)
			if (lst->map[fgr->x + x][fgr->y + y])
				flag++;
		if (flag > 1)
			return (0);
		fgr = fgr->next;
	}
	if (flag != 1)
		return (0);
	return (1);
}

void	find_place(t_flist *lst, t_figure *fgr)
{
	int 	x;
	int 	y;

	x = 0;
	lst->min_dist = 100000;
	lst->bestx = 0;
	lst->besty = 0;
	while (x != lst->height)
	{
		y = 0;
		while (y != lst->width)
		{
			if (check_valid_place(lst, fgr, x, y))
				check_best_plase(lst, fgr, x, y);
			y++;
		}
		x++;
	}
	lst->order++;
	ft_printf("%d %d\n", lst->bestx, lst->besty);
}