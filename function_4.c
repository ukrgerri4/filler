#include "filler.h"

void	find_limit_coordinates(t_flist *lst, int x, int y)
{
	lst->x[0] = 0;
	if (y <= (lst->width / 2) && x <= (lst->height / 2))
	{
		lst->y[0] = lst->width;
		lst->x[1] = lst->height;
		lst->y[1] = lst->width / 2;
	}
	else if (y <= (lst->width / 2) && x > (lst->height / 2))
	{
		lst->y[0] = lst->width / 2;
		lst->x[1] = lst->height;
		lst->y[1] = lst->width;
	}
	else if (y >= (lst->width / 2) && x <= (lst->height / 2))
	{
		lst->y[0] = 0;
		lst->x[1] = lst->height;
		lst->y[1] = lst->width / 2;
	}
	else
	{
		lst->y[0] = lst->width / 2;
		lst->x[1] = lst->height;
		lst->y[1] = 0;
	}
}

void 	find_plr_place(t_flist *lst)
{
	int 	x;
	int 	y;

	x = 0;
	while (x != lst->height)
	{
		y = 0;
		while (y != lst->width)
		{
			if (lst->map[x][y] == 2)
				find_limit_coordinates(lst, x, y);
			y++;
		}
		x++;
	}
	lst->flag++;
}
