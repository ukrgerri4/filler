/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:27:21 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:45:02 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_winner(char *line)
{
	int i;
	int p1;
	int p2;

	i = 0;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	p1 = ft_atoi(&line[i]);
	get_next_line(0, &line);
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	p2 = ft_atoi(&line[i]);
	if (p1 > p2)
		ft_printf("\033[1;32mPlr O - Win with %d against %d\n\033[0m", p1, p2);
	else
		ft_printf("\033[1;32mPlr X - Win with %d against %d\n\033[0m", p2, p1);
}

void	print_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '.')
			ft_printf("\033[30;47m.\033[0m");
		else if (line[i] == 'O')
			ft_printf("\033[37;42mO\033[0m");
		else if (line[i] == 'o')
			ft_printf("\033[37;42mo\033[0m");
		else if (line[i] == 'X')
			ft_printf("\033[37;41mX\033[0m");
		else if (line[i] == 'x')
			ft_printf("\033[37;41mx\033[0m");
		i++;
	}
	ft_printf("\n");
}

int		main(void)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (line[0] == 'P' && ft_strstr(line, "Plateau"))
		{
			while (get_next_line(0, &line) && !(ft_strstr(line, "Piece")))
				if (line[0] == '0')
					print_line(line);
			ft_printf("\n");
		}
		if (line[0] == '=')
			check_winner(line);
	}
	return (0);
}
