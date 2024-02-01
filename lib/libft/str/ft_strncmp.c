/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:29:12 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/05 12:06:05 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:compares not more than n characters.  Because strncmp() is
designed for comparing strings rather than binary data, characters
that appear after a `\0' character are not compared.
Return:return an integer greater than, equal to, or less than 0,
according as the string s1 is greater than, equal to, or less
than the string s2.  The comparison is done using unsigned characters,
so that `\200' is greater than `\0'.*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	if (!s1 || !s2)
		return (1);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
