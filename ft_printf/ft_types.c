/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:31:19 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/04 19:32:00 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_sign_t(t_plist *rules, va_list ap)
{
	ssize_t tmp;

	if ((rules->length & 32))
		return (tmp = va_arg(ap, size_t));
	else if ((rules->length & 16))
		return (tmp = va_arg(ap, intmax_t));
	else if ((rules->length & 8))
		return (tmp = va_arg(ap, long long int));
	else if ((rules->length & 4))
		return (tmp = va_arg(ap, long int));
	else if ((rules->length & 2))
		return (tmp = (short int)va_arg(ap, int));
	else if ((rules->length & 1))
		return (tmp = (signed char)va_arg(ap, int));
	else
		return (tmp = va_arg(ap, int));
}

size_t	ft_unsign_t(t_plist *rules, va_list ap)
{
	size_t tmp;

	if ((rules->length & 32))
		return (tmp = va_arg(ap, size_t));
	else if ((rules->length & 16))
		return (tmp = va_arg(ap, uintmax_t));
	else if ((rules->length & 8))
		return (tmp = va_arg(ap, unsigned long long int));
	else if ((rules->length & 4))
		return (tmp = va_arg(ap, unsigned long int));
	else if ((rules->length & 2))
		return (tmp = (unsigned short)va_arg(ap, int));
	else if ((rules->length & 1))
		return (tmp = (unsigned char)va_arg(ap, int));
	else
		return (tmp = va_arg(ap, unsigned int));
}
