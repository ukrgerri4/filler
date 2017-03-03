/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_wstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:55:14 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/07 15:59:01 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_precision(t_plist *rules, wchar_t *s)
{
	while (rules->precision > 0)
	{
		ft_putwchar_count(*(s++));
		rules->precision = rules->precision - g_wcount;
	}
}

static void	ft_pws_align_on(t_plist *rules, wchar_t *s)
{
	if (rules->precision != -1 && rules->precision < rules->len)
		if (rules->width > rules->precision)
		{
			rules->len = rules->width - rules->precision;
			ft_write_precision(rules, s);
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
		else
			ft_write_precision(rules, s);
	else
	{
		ft_putwstr_count(s);
		if (rules->width && rules->width > rules->len)
		{
			rules->len = rules->width - rules->len;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
	}
}

static void	ft_pws_align_off(t_plist *rules, wchar_t *s)
{
	if (rules->precision != -1 && rules->precision < rules->len)
		if (rules->width > rules->precision)
		{
			rules->len = rules->width - rules->precision;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
			ft_write_precision(rules, s);
		}
		else
			ft_write_precision(rules, s);
	else
	{
		if (rules->width && rules->width > rules->len)
		{
			rules->len = rules->width - rules->len;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
		ft_putwstr_count(s);
	}
}

void		ft_print_ws(t_plist *rules, wchar_t *s)
{
	if (!s)
	{
		ft_print_s(rules, "(null)");
		return ;
	}
	rules->len = ft_wstrlen(s);
	if (rules->precision > 0)
		rules->precision = ft_fix_prec(rules->precision, s);
	if (rules->flags & 2)
		ft_pws_align_on(rules, s);
	else
		ft_pws_align_off(rules, s);
}

void		ft_print_wc(t_plist *rules, wint_t c)
{
	rules->len = 1;
	if (rules->flags & 2)
	{
		ft_putwchar_count(c);
		if (rules->width && rules->width > rules->len)
		{
			rules->len = rules->width - rules->len;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
	}
	else
	{
		if (rules->width && rules->width > rules->len)
		{
			rules->len = rules->width - rules->len;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
		ft_putwchar_count(c);
	}
}
