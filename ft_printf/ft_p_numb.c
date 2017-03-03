/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dDioOuUxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:51:53 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/07 16:00:32 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_prefix(t_plist *rules, char **s, char c, int *i)
{
	if (*s[0] == '-')
	{
		rules->prefix[0] = '-';
		*i = 1;
		(*s)++;
	}
	else if ((c == 'o' || c == 'O') && (rules->flags & 8) && *s[0] != '0')
	{
		rules->prefix[0] = '0';
		*i = (rules->precision > rules->len) ? 0 : 1;
	}
	else if ((c == 'x' || c == 'X') && (rules->flags & 8) && *s[0] != '0')
	{
		rules->prefix[0] = '0';
		rules->prefix[1] = (c == 'x') ? 'x' : 'X';
		*i = 2;
	}
	else if ((rules->flags & 4) && !(rules->flags & 1) && !(c == 'o'
				|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'))
	{
		rules->prefix[0] = ' ';
		*i = 1;
	}
	else
		rules->prefix[0] = '+';
}

static void	ft_check_prefix_p(t_plist *rules, char *s, char c, int *i)
{
	if (c == 'p')
	{
		ft_tolower_str(s);
		rules->prefix[0] = '0';
		rules->prefix[1] = 'x';
		*i = 2;
	}
}

static void	ft_alignment_on(t_plist *rules, char *s, char c, int i)
{
	int j;

	if (i)
		ft_putstr_count(rules->prefix);
	if ((j = rules->precision - rules->len) > 0)
		while (j--)
			ft_putchar_count('0');
	(c == 'x') ? ft_putstr_count(ft_tolower_str(s)) : ft_putstr_count(s);
	rules->len = (rules->precision >= rules->len)
		? rules->precision : rules->len;
	if ((j = rules->width - (i + rules->len)) > 0)
		while (j--)
			ft_putchar_count(' ');
}

static void	ft_alignment_off(t_plist *rules, char *s, char c, int i)
{
	int j;

	if (rules->precision != -1)
	{
		rules->precision = (rules->precision >= rules->len) ?
			rules->precision : rules->len;
		if ((j = rules->width - (i + rules->precision)) > 0)
			while (j--)
				ft_putchar_count(' ');
		if (i)
			ft_putstr_count(rules->prefix);
		while ((rules->len)++ != rules->precision)
			ft_putchar_count('0');
	}
	else
	{
		if (i && rules->prep == '0')
			ft_putstr_count(rules->prefix);
		if ((j = rules->width - (i + rules->len)) > 0)
			while (j--)
				ft_putchar_count(rules->prep);
		if (i && rules->prep == ' ')
			ft_putstr_count(rules->prefix);
	}
	(c == 'x') ? ft_putstr_count(ft_tolower_str(s)) : ft_putstr_count(s);
}

void		ft_pnumb(t_plist *rules, char *s, char c)
{
	int		i;
	char	*string;

	string = s;
	rules->prep = (rules->flags & 16) ? '0' : ' ';
	i = 0;
	if (rules->precision == 0 && s[0] == '0')
	{
		if (c == 'x' || c == 'X')
			rules->flags = 0;
		s[0] = '\0';
	}
	rules->len = ft_strlen(s);
	ft_check_prefix(rules, &s, c, &i);
	ft_check_prefix_p(rules, s, c, &i);
	i = ((rules->flags & 1) && !(c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')) ? 1 : i;
	rules->len = ft_strlen(s);
	if (rules->flags & 2)
		ft_alignment_on(rules, s, c, i);
	else
		ft_alignment_off(rules, s, c, i);
	ft_strdel(&string);
}
