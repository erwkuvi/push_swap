/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:33:13 by ekuchel           #+#    #+#             */
/*   Updated: 2024/02/01 16:03:40 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	reverse_rotate_stack(t_stack **stack, char *move)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		print_error();
	tmp2 = *stack;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp1 = tmp2->next;
	tmp1->next = *stack;
	tmp2->next = NULL;
	*stack = tmp1;
	printmove(move);
}

void	reverse_rotate_both(t_stack **stack1, t_stack **stack2)
{
	reverse_rotate_stack(stack1, NULL);
	reverse_rotate_stack(stack2, NULL);
	printmove("rrr");
}

void	sort3(t_stack **stack)
{
	if (stack_size(*stack) != 3)
		return ;
	while (1)
	{
		if (((*stack)->value < (*stack)->next->value
				&& (*stack)->next->value > (*stack)->next->next->value))
			reverse_rotate_stack(stack, "rra");
		if ((*stack)->value > (*stack)->next->value
			&& (*stack)->next->value > (*stack)->next->next->value)
			rotate_stack(stack, "ra");
		if ((*stack)->value > (*stack)->next->value
			&& (*stack)->next->value < (*stack)->next->next->value)
		{
			if ((*stack)->value < (*stack)->next->next->value)
				swap_stack(stack, "sa");
			else
				rotate_stack(stack, "ra");
		}
		if ((*stack)->value < (*stack)->next->value
			&& (*stack)->next->value < (*stack)->next->next->value)
		{
			return ;
		}
	}
}

void	sort2(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap_stack(stack, "sa");
	free_list(*stack);
}
