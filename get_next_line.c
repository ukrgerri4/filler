/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:45:59 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/01/16 18:46:32 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			write_rest(t_buf *s_fdlist, char **line, int fd)
{
	int i;

	i = 0;
	if (s_fdlist)
	{
		while (s_fdlist->fd != fd && s_fdlist->next)
			s_fdlist = s_fdlist->next;
		if (s_fdlist->fd == fd && s_fdlist->buf[i])
		{
			while (s_fdlist->buf[i] && s_fdlist->buf[i] != '\n')
			{
				(*line)[i] = s_fdlist->buf[i];
				i++;
			}
			if (s_fdlist->buf[i] == '\n')
			{
				ft_memmove(&s_fdlist->buf[0], &s_fdlist->buf[i + 1],
						(ft_strlen(s_fdlist->buf) - i));
				return (1);
			}
			ft_bzero(&s_fdlist->buf[0], BUFF_SIZE + 1);
		}
	}
	return (0);
}

static int			add_list(t_buf **s_fdlist, char *buf, int fd)
{
	t_buf	*tmp;

	tmp = *s_fdlist;
	if (tmp)
	{
		while (tmp->fd != fd && tmp->next)
			tmp = tmp->next;
		if (tmp->fd == fd)
		{
			tmp->buf = ft_strcpy(tmp->buf, buf);
			return (1);
		}
	}
	tmp = (t_buf*)malloc(sizeof(t_buf));
	tmp->fd = fd;
	tmp->buf = ft_strnew(BUFF_SIZE);
	tmp->buf = ft_strcpy(tmp->buf, buf);
	if (*s_fdlist)
		tmp->next = *s_fdlist;
	else
		tmp->next = NULL;
	*s_fdlist = tmp;
	return (1);
}

static char			*add_memory(char *line, int len)
{
	char	*str;

	str = ft_strnew(len);
	str = ft_strcpy(str, line);
	free(line);
	line = 0;
	return (str);
}

static int			write_line(t_buf **s_fdlist, char **line, int fd, int len)
{
	char	buf[BUFF_SIZE + 1];
	int		rbyte;
	int		i;

	i = 0;
	while ((*line)[i])
		i++;
	while ((rbyte = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rbyte] = '\0';
		rbyte = 0;
		while (buf[rbyte] && buf[rbyte] != '\n')
		{
			if (i == len)
				*line = add_memory(*line, len *= 2);
			(*line)[i++] = buf[rbyte++];
		}
		if (buf[rbyte] == '\n')
			return (add_list(s_fdlist, &buf[++rbyte], fd));
	}
	return (rbyte);
}

int					get_next_line(const int fd, char **line)
{
	static t_buf	*s_fdlist;
	int				rbyte;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (write_rest(s_fdlist, line, fd))
		return (1);
	rbyte = write_line(&s_fdlist, line, fd, BUFF_SIZE);
	if (!rbyte && !**line)
		return (0);
	if (rbyte < 0)
		return (-1);
	return (1);
}
