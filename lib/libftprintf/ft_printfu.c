/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:11:36 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/11 14:53:26 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfu(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_printfc(n + '0');
	else
	{
		len += ft_printfd(n / 10);
		len += ft_printfd(n % 10);
	}
	return (len);
}
