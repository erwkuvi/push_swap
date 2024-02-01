/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:48 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/05 18:21:18 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	ft_add_first(t_stack **head, int value)
{
	t_stack	*new_item;

	new_item = (t_stack *)malloc(sizeof(t_stack));
	new_item->value = value;
	new_item->next = *head;
	*head = new_item;
	(*head)->next = NULL;
}

void	digit_compare_new(int *argv_stack, int index, int value)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < index)
	{
		if (argv_stack[i] == value)
			flag = 1;
		i++;
	}
	if (flag)
		print_error();
}

// int	digit_compare(char **argv, int index, int value)
// {
// 	int	i;

// 	i = 1;
// 	while (i < index)
// 	{
// 		if (ft_atoi(argv[i]) == value)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

long	ft_atoil(const char *str)
{
	int		i;
	long	res;
	int		posneg;

	posneg = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			posneg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res = res + (str[i] - '0');
		i++;
	}
	check_max_min_new(res);
	return (res * posneg);
}

void	create_stack_new(int count, int *argv_stack, t_stack **stack)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_addnode(stack, argv_stack[i]);
		i++;
	}
	ft_stack_c_new((*stack), count);
	free(argv_stack);
}

int	stack_size(t_stack *stack)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
