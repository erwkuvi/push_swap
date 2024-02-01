/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:02:26 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 15:18:42 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	assign_pos(t_stack *stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = stack;
	while (current->next != NULL)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
	current->pos = i;
}

int	valuecmp(int value1, int value2)
{
	if (value1 != value2)
		return (1);
	return (0);
}

void	assign_index_new(t_stack *stack, int *array, int count)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		i = 0;
		while (i < count)
		{
			if (!valuecmp(current->value, array[i]))
				current->index = i + 1;
			i++;
		}
		current = current->next;
	}
}

// void	assign_index(t_stack *stack, int *array, int argc)
// {
// 	t_stack	*current;
// 	int		i;

// 	i = 0;
// 	current = stack;
// 	while (current != NULL)
// 	{
// 		i = 0;
// 		while (i < argc - 1)
// 		{
// 			if (!valuecmp(current->value, array[i]))
// 				current->index = i + 1;
// 			i++;
// 		}
// 		current = current->next;
// 	}
// }

void	pb_all_sorted_new(t_stack **stack_b, t_stack **stack_a, int count)
{
	int	j;
	int	total_values;

	total_values = count;
	j = 0;
	while (j < (total_values / 2))
	{
		if ((*stack_a)->index <= (total_values / 2))
		{
			push_to_stack(stack_b, stack_a, "pb");
			j++;
		}
		else
			rotate_stack(stack_a, "ra");
	}
	while (j < (total_values - 3))
	{
		push_to_stack(stack_b, stack_a, "pb");
		j++;
	}
}

// void	pb_all_sorted(t_stack **stack_b, t_stack **stack_a, int argc)
// {
// 	int	j;
// 	int	total_values;

// 	total_values = argc - 1;
// 	j = 0;
// 	while (j < (total_values / 2))
// 	{
// 		if ((*stack_a)->index <= (total_values / 2))
// 		{
// 			push_to_stack(stack_b, stack_a, "pb");
// 			j++;
// 		}
// 		else
// 			rotate_stack(stack_a, "ra");
// 	}
// 	while (j < (total_values - 3))
// 	{
// 		push_to_stack(stack_b, stack_a, "pb");
// 		j++;
// 	}
// }
