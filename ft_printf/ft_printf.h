/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 20:07:24 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/07 15:58:41 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stddef.h>
# include <inttypes.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

int				g_count;
int				g_wcount;

typedef	struct	s_plist
{
	int		flags;
	int		width;
	int		precision;
	int		length;
	char	prefix[3];
	char	prep;
	int		len;
}				t_plist;

int				ft_printf(const char *format, ...);
/*
** check all parameters
*/
int				ft_checkparam(t_plist *rules, const char *format,
		va_list ap, int *i);
int				ft_end_char(char c);
void			ft_write_pad(t_plist *rules, const char *c, int *i);
void			ft_write_flags(t_plist *rules, char c);
void			ft_create_plist(t_plist **rules);
void			ft_write_length(t_plist *rules, const char *c, int *i);
/*
** use saved parameters and write specifier
*/
void			ft_pnumb(t_plist *rules, char *s, char c);
void			ft_userstring(t_plist *rules, char c, va_list ap);
ssize_t			ft_sign_t(t_plist *rules, va_list ap);
size_t			ft_unsign_t(t_plist *rules, va_list ap);
void			ft_usernumb(t_plist *rules, char c, va_list ap);
int				ft_fix_prec(int d, wchar_t *str);
/*
** write function
*/
void			ft_putchar_count(int c);
void			ft_putstr_count(char *s);
void			ft_putwchar_count(wint_t c);
void			ft_putwstr_count(wchar_t *s);
char			*ft_itoa_base_s(ssize_t value, int base);
char			*ft_itoa_base_us(size_t value, int base);
char			*ft_tolower_str(char *s);
/*
** libft function
*/
int				ft_atoi(const char *str);
void			ft_bzero(void *str, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(wchar_t *str);
void			ft_strdel(char **as);
void			ft_print_s(t_plist *rules, char *s);
void			ft_print_c(t_plist *rules, char c);
void			ft_print_wc(t_plist *rules, wint_t c);
void			ft_print_ws(t_plist *rules, wchar_t *s);
#endif
