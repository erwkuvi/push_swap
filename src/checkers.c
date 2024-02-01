/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:49:04 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 13:09:18 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	check_max_min_new(long value)
{
	int	size;
	int	max;
	int	min;

	size = sizeof(int) * 8;
	min = -((unsigned int)1 << (size - 1));
	max = (1 << (size - 1)) - 1;
	if (value > max || value < min)
		print_error();
}

void	check_sorted(int count, int *argv_stack)
{
	int	i;

	i = -1;
	while (++i + 1 < count)
	{
		if (argv_stack[i] > argv_stack[i + 1])
			return ;
	}
	exit(0);
}

int	if_smallest(int *smallest, int *argv_stack, int i)
{
	*smallest = 1;
	return (argv_stack[i + 1]);
}

int	cyclicalsorted_new(t_stack *stack_a)
{
	t_stack	*current;
	int		flag;

	flag = 0;
	current = stack_a;
	while (current->next != NULL)
	{
		if (current->next->next == NULL
			&& current->next->index > stack_a->index)
			return (0);
		if (current->index > current->next->index
			&& current->index != max_index(stack_a)->index
			&& current->next->index != min_index(stack_a)->index)
			return (0);
		if (current->index == max_index(stack_a)->index
			&& current->next->index == min_index(stack_a)->index)
			flag = 1;
		current = current->next;
	}
	return (flag);
}

// int	cyclicalsorted_new(int count, t_stack *stack_a)
// {
// 	int	i;
// 	int	smallest;
// 	int	smallest_value;

// 	i = 0;
// 	smallest = 0;
// 	smallest_value = argv_stack[i];
// 	while (i + 1 < count)
// 	{
// 		if (argv_stack[i] > argv_stack[i + 1])
// 		{
// 			if (!smallest)
// 				if_smallest(&smallest, argv_stack, i);
// 			else
// 				return (0);
// 		}
// 		i++;
// 	}
// 	if (smallest && argv_stack[1] < smallest_value)
// 		return (0);
// 	return (1);
// }
