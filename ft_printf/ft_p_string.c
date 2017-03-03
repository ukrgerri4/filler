/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 20:24:57 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/03 16:52:18 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ps_align_on(t_plist *rules, char *s)
{
	if (rules->precision != -1 && rules->precision < rules->len)
		if (rules->width > rules->precision)
		{
			rules->len = rules->width - rules->precision;
			while (rules->precision-- > 0)
				ft_putchar_count(*(s++));
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
		else
			while (rules->precision-- > 0)
				ft_putchar_count(*(s++));
	else
	{
		ft_putstr_count(s);
		if (rules->width && rules->width > rules->len)
		{
			rules->len = rules->width - rules->len;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
	}
}

static void	ft_ps_align_off(t_plist *rules, char *s)
{
	if (rules->precision != -1 && rules->precision < rules->len)
		if (rules->width > rules->precision)
		{
			rules->len = rules->width - rules->precision;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
			while (rules->precision-- > 0)
				ft_putchar_count(*(s++));
		}
		else
			while (rules->precision-- > 0)
				ft_putchar_count(*(s++));
	else
	{
		if (rules->width && rules->width > rules->len)
		{
			rules->len = rules->width - rules->len;
			while ((rules->len)--)
				((rules->flags & 16) && !(rules->flags & 2))
					? ft_putchar_count('0') : ft_putchar_count(' ');
		}
		ft_putstr_count(s);
	}
}

void		ft_print_s(t_plist *rules, char *s)
{
	if (!s)
		s = "(null)";
	rules->len = ft_strlen(s);
	if (rules->flags & 2)
		ft_ps_align_on(rules, s);
	else
		ft_ps_align_off(rules, s);
}

void		ft_print_c(t_plist *rules, char c)
{
	rules->len = 1;
	if (rules->flags & 2)
	{
		ft_putchar_count(c);
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
		ft_putchar_count(c);
	}
}

void		ft_userstring(t_plist *rules, char c, va_list ap)
{
	if (c == '%')
		ft_print_c(rules, '%');
	else if ((c == 'c' && (rules->length &= 4)) || c == 'C')
		ft_print_wc(rules, va_arg(ap, wint_t));
	else if ((c == 's' && (rules->length &= 4)) || c == 'S')
		ft_print_ws(rules, va_arg(ap, wchar_t*));
	else if (c == 'c')
		ft_print_c(rules, va_arg(ap, int));
	else if (c == 's')
		ft_print_s(rules, va_arg(ap, char*));
}
