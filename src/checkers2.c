/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:22:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 17:41:34 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error();
		i++;
	}
}

int	count_len(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			isnum(str[j]);
			count++;
			j++;
		}
		free_char_array(str);
		i++;
	}
	return (count);
}

int	*arg2stack(int argc, char **argv, int count)
{
	int		i;
	int		j;
	int		k;
	char	**str;
	int		*digit;

	digit = malloc(count * sizeof(int));
	if (!digit)
		return (NULL);
	i = 0;
	k = 0;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			digit[k] = ft_atoil(str[j]);
			digit_compare_new(digit, k, digit[k]);
			k++;
			j++;
		}
		free_char_array(str);
	}
	return (digit);
}
