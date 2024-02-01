/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:53:43 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/05 18:20:13 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	swap_stack(t_stack **stack, char *move)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		print_error();
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*stack = tmp2;
	printmove(move);
}

void	swap_both(t_stack **stack1, t_stack **stack2)
{
	if (*stack1 == NULL || *stack2 == NULL)
		print_error();
	swap_stack(stack1, NULL);
	swap_stack(stack2, NULL);
	printmove("ss");
}

void	push_to_stack(t_stack **des_stack, t_stack **src_stack, char *move)
{
	t_stack	*tmp;

	if (*src_stack == NULL)
		print_error();
	tmp = *src_stack;
	*src_stack = (*src_stack)->next;
	tmp->next = *des_stack;
	*des_stack = tmp;
	printmove(move);
}

void	rotate_stack(t_stack **stack, char *move)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		print_error();
	tmp2 = *stack;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp1 = *stack;
	tmp2->next = tmp1;
	*stack = (*stack)->next;
	tmp1->next = NULL;
	printmove(move);
}

void	rotate_both(t_stack **stack1, t_stack **stack2)
{
	rotate_stack(stack1, NULL);
	rotate_stack(stack2, NULL);
	printmove("rr");
}
