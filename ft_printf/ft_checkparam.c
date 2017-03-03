/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:41:00 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/02 13:25:39 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_usernumb(t_plist *rules, char c, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'D')
	{
		if (c == 'D')
			rules->length |= 4;
		ft_pnumb(rules, ft_itoa_base_s(ft_sign_t(rules, ap), 10), c);
	}
	else if (c == 'o' || c == 'O')
	{
		if (c == 'O')
			rules->length |= 4;
		ft_pnumb(rules, ft_itoa_base_us(ft_unsign_t(rules, ap), 8), c);
	}
	else if (c == 'u' || c == 'U')
	{
		if (c == 'U')
			rules->length |= 4;
		ft_pnumb(rules, ft_itoa_base_us(ft_unsign_t(rules, ap), 10), c);
	}
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		if (c == 'p')
			rules->length |= 32;
		ft_pnumb(rules, ft_itoa_base_us(ft_unsign_t(rules, ap), 16), c);
	}
}

static void	ft_use_rules(t_plist *rules, char c, va_list ap)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == '%')
		ft_userstring(rules, c, ap);
	else if (c == 'd' || c == 'D' || c == 'i' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'p')
		ft_usernumb(rules, c, ap);
}

static void	ft_non_spec(t_plist *rules, char c, int *i)
{
	if (rules->flags & 2)
	{
		ft_putchar_count(c);
		while (--rules->width > 0)
			ft_putchar_count(' ');
		(*i)++;
	}
	else
		while (--rules->width > 0)
			(rules->flags & 16) ? ft_putchar_count('0')
		: ft_putchar_count(' ');
}

int			ft_checkparam(t_plist *rules, const char *format,
		va_list ap, int *i)
{
	ft_create_plist(&rules);
	(*i)++;
	while (!ft_end_char(format[*i]) && format[*i])
	{
		if ((format[*i] >= '1' && format[*i] <= '9') || format[*i] == '.')
			ft_write_pad(rules, format, i);
		else if (format[*i] == '+' || format[*i] == '-' || format[*i] == ' '
				|| format[*i] == '0' || format[*i] == '#')
			ft_write_flags(rules, format[(*i)++]);
		else if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j'
				|| format[*i] == 'z')
			ft_write_length(rules, &format[(*i)++], i);
		else
		{
			ft_non_spec(rules, format[*i], i);
			return (1);
		}
	}
	if (!format[*i])
		return (0);
	ft_use_rules(rules, format[*i], ap);
	(*i)++;
	return (1);
}
