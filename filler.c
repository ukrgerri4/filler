#include "filler.h"

int		main(void)
{
	t_flist				lst;
	t_figure			*fgr;
	char 				*line;

	fgr = 0;
	lst.flag = 0;
	lst.order = 0;
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
	return 0;
}
