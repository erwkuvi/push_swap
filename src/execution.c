/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:22:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 16:34:24 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	smallest_val(t_stack *b, char *pos_or_neg)
{
	if (!ft_strcmp(pos_or_neg, "pos"))
	{
		if (b->cost_a > b->cost_b)
			return (b->cost_b);
		else
			return (b->cost_a);
	}
	if (!ft_strcmp(pos_or_neg, "neg"))
	{
		if (b->cost_b > b->cost_a)
			return (b->cost_b);
		else
			return (b->cost_a);
	}
	print_error();
	return (b->cost_a);
}

void	cost_both_neg(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	int	i;

	i = 1;
	while (--i > smallest_val(cheap, "neg"))
		reverse_rotate_both(stack_a, stack_b);
	while (i > smallest_val(cheap, "pos"))
	{
		if (cheap->cost_a == smallest_val(cheap, "pos"))
			reverse_rotate_stack(stack_a, "rra");
		if (cheap->cost_b == smallest_val(cheap, "pos"))
			reverse_rotate_stack(stack_b, "rrb");
		i--;
	}
}

void	cost_both_pos(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	int	i;

	i = -1;
	while (++i < smallest_val(cheap, "pos"))
		rotate_both(stack_a, stack_b);
	while (i < smallest_val(cheap, "neg"))
	{
		if (cheap->cost_a == smallest_val(cheap, "neg"))
			rotate_stack(stack_a, "ra");
		if (cheap->cost_b == smallest_val(cheap, "neg"))
			rotate_stack(stack_b, "rb");
		i++;
	}
}

void	cost_diff(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	int	i;

	if (cheap->cost_a < 0)
	{
		i = 1;
		while (--i > cheap->cost_a)
			reverse_rotate_stack(stack_a, "rra");
		i = -1;
		while (++i < cheap->cost_b)
			rotate_stack(stack_b, "rb");
	}
	else
	{
		i = 1;
		while (--i > cheap->cost_b)
			reverse_rotate_stack(stack_b, "rrb");
		i = -1;
		while (++i < cheap->cost_a)
			rotate_stack(stack_a, "ra");
	}
}

void	rotate_cheapest(t_stack	**stack_a, t_stack **stack_b, t_stack *cheap)
{
	if (cheap->cost_a < 0 && cheap->cost_b < 0)
		cost_both_neg(stack_a, stack_b, cheap);
	else if (cheap->cost_a >= 0 && cheap->cost_b >= 0)
		cost_both_pos(stack_a, stack_b, cheap);
	else
		cost_diff(stack_a, stack_b, cheap);
}
