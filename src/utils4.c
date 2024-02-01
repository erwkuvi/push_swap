/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:59:23 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/05 12:09:20 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_stack	*min_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_idx_stack;

	current = stack;
	min_idx_stack = stack;
	while (current != NULL)
	{
		if (current->index < min_idx_stack->index)
			min_idx_stack = current;
		current = current->next;
	}
	return (min_idx_stack);
}

t_stack	*max_index(t_stack *stack)
{
	t_stack	*max_idx_stack;
	t_stack	*current_a;

	current_a = stack;
	max_idx_stack = stack;
	while (current_a != NULL)
	{
		if (current_a->index > max_idx_stack->index)
			max_idx_stack = current_a;
		current_a = current_a->next;
	}
	return (max_idx_stack);
}

void	index_control_new(t_stack *current_a, t_stack *current_b, int count,
		int *current_idx)
{
	int	i;

	i = -1;
	while (++i < (count - current_b->index))
	{
		if (current_b->index + 1 + i == current_a->index)
		{
			if (current_a->index <= *current_idx)
			{
				*current_idx = current_a->index;
				current_b->target_pos = current_a->pos;
			}
		}
	}
}

// void	index_control(t_stack *current_a, t_stack *current_b, int argc,
// 		int *current_idx)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < (argc - 1 - current_b->index))
// 	{
// 		if (current_b->index + 1 + i == current_a->index)
// 		{
// 			if (current_a->index <= *current_idx)
// 			{
// 				*current_idx = current_a->index;
// 				current_b->target_pos = current_a->pos;
// 			}
// 		}
// 	}
// }

void	assign_target_pos_new(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		current_idx;

	assign_pos(stack_a);
	assign_pos(stack_b);
	current_b = stack_b;
	while (current_b != NULL)
	{
		current_a = stack_a;
		current_idx = (max_index(stack_a))->index;
		while (current_a != NULL)
		{
			index_control_new(current_a, current_b, count, &current_idx);
			current_a = current_a->next;
		}
		if (current_b->index > max_index(stack_a)->index)
			current_b->target_pos = min_index(stack_a)->pos;
		current_b = current_b->next;
	}
}

// void	assign_target_pos(t_stack *stack_a, t_stack *stack_b, int argc)
// {
// 	t_stack	*current_a;
// 	t_stack	*current_b;
// 	int		current_idx;

// 	assign_pos(stack_a);
// 	assign_pos(stack_b);
// 	// ft_printf("Min idx node\n");
// 	// ft_printf("value\n");
// 	current_b = stack_b;
// 	while (current_b != NULL)
// 	{
// 		current_a = stack_a;
// 		current_idx = (max_index(stack_a))->index;
// 		while (current_a != NULL)
// 		{
// 			index_control(current_a, current_b, argc, &current_idx);
// 			current_a = current_a->next;
// 		}
// 		if (current_b->index > max_index(stack_a)->index)
// 			current_b->target_pos = min_index(stack_a)->pos;
// 		current_b = current_b->next;
// 	}
// }

void	assign_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;

	current_b = stack_b;
	while (current_b != NULL)
	{
		if (current_b->pos <= (stack_size(stack_b) / 2))
			current_b->cost_b = current_b->pos;
		else
			current_b->cost_b = (stack_size(stack_b) - current_b->pos) * -1;
		if (current_b->target_pos <= (stack_size(stack_a) / 2))
			current_b->cost_a = current_b->target_pos;
		else
			current_b->cost_a = (stack_size(stack_a)
					- current_b->target_pos) * -1;
		current_b = current_b->next;
	}
}
