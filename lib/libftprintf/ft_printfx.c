/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:19 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/11 15:26:36 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfx(unsigned long n, char c)
{
	int		len;
	char	*hex;

	len = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n < 16)
		len += ft_printfc(hex[n]);
	else
	{
		len += ft_printfx((n / 16), c);
		len += ft_printfx((n % 16), c);
	}
	return (len);
}
