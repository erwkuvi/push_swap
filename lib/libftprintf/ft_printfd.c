/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:11:36 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/10 13:38:26 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfd(int n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		len += ft_printfc('-');
	}
	if (num < 10)
		len += ft_printfc((num + '0'));
	else
	{
		len += ft_printfd(num / 10);
		len += ft_printfd(num % 10);
	}
	return (len);
}
