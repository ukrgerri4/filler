/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_wstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:16:50 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/05 18:19:27 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwchar_2byte(unsigned char *s, wint_t c)
{
	g_wcount = 2;
	s[1] |= c;
	s[1] = s[1] << 2;
	s[1] = s[1] >> 2;
	s[1] |= 128;
	s[0] |= 192;
	s[0] |= c >> 6;
	write(1, s, 2);
	g_count = g_count + g_wcount;
}

static void	ft_putwchar_3byte(unsigned char *s, wint_t c)
{
	g_wcount = 3;
	s[2] |= c;
	s[2] = s[2] << 2;
	s[2] = s[2] >> 2;
	s[2] |= 128;
	s[1] |= c >> 6;
	s[1] = s[1] << 2;
	s[1] = s[1] >> 2;
	s[1] |= 128;
	s[0] |= 224;
	s[0] |= c >> 12;
	write(1, s, 3);
	g_count = g_count + g_wcount;
}

static void	ft_putwchar_4byte(unsigned char *s, wint_t c)
{
	g_wcount = 4;
	s[3] |= c;
	s[3] = s[3] << 2;
	s[3] = s[3] >> 2;
	s[3] |= 128;
	s[2] |= c >> 6;
	s[2] = s[2] << 2;
	s[2] = s[2] >> 2;
	s[2] |= 128;
	s[1] |= c >> 12;
	s[1] = s[1] << 2;
	s[1] = s[1] >> 2;
	s[1] |= 128;
	s[0] |= 240;
	s[0] |= c >> 18;
	write(1, s, 4);
	g_count = g_count + g_wcount;
}

void		ft_putwchar_count(wint_t c)
{
	static unsigned char s[4];

	g_wcount = 1;
	if (c >= 0x0 && c <= 0x7F)
	{
		s[0] |= c;
		write(1, s, 1);
		g_count = g_count + g_wcount;
	}
	else if (c >= 0x80 && c <= 0x7FF)
		ft_putwchar_2byte(s, c);
	else if (c >= 0x800 && c <= 0xFFFF)
		ft_putwchar_3byte(s, c);
	else if (c >= 0x10000 && c <= 0x1FFFFF)
		ft_putwchar_4byte(s, c);
	ft_bzero(s, 4);
}

void		ft_putwstr_count(wchar_t *s)
{
	while (*s)
		ft_putwchar_count(*(s++));
}
