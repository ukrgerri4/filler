#include "filler.h"

void	ft_fgr_delete(t_figure **fgr)
{
	t_figure *tmp;

	if (fgr)
	{
		if (*fgr)
		{
			while (*fgr)
			{
				tmp = (*fgr)->next;
				free(*fgr);
				(*fgr) = 0;
				(*fgr) = tmp;
			}
		}
	}
	else
		return ;
}

static t_figure	*create_element(int x, int y, char c)
{
	t_figure *result;

	result = (t_figure*)malloc(sizeof(t_figure));
	if (result)
	{
		result->x = x;
		result->y = y;
		if (c == '.')
			result->f = 0;
		else
			result->f = 1;
		result->next = NULL;
	}
	return (result);
}

static void	element_push_back(t_figure **begin_list, int x, int y, char c)
{
	t_figure	*result;

	result = *begin_list;
	if (result)
	{
		while (result->next)
			result = result->next;
		result->next = create_element(x, y, c);
	}
	else
		*begin_list = create_element(x, y, c);
}

static int			number_of_call_gnl(char *line)
{
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
			return (ft_atoi(line));
		line++;
	}
	return (0);
}

void		check_figure(char *line, t_figure **fgr)
{
	int j;
	int i;
	int	x;
	int	y;

	j = number_of_call_gnl(line);
	x = 0;
	while (j)
	{
		get_next_line(0, &line);
		i = 0;
		y = 0;
		while (line[i])
		{
			element_push_back(fgr, x, y, line[i++]);
			y++;
		}
		x++;
		j--;
	}
}