/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:17:49 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 16:57:26 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	cost(t_stack *node)
{
	int	total;
	int	neg_a;
	int	neg_b;

	neg_a = 1;
	neg_b = 1;
	if (node->cost_a >= 0 && node->cost_b >= 0)
		return (smallest_val(node, "neg"));
	if (node->cost_a < 0 && node->cost_b < 0)
		return (smallest_val(node, "pos") * -1);
	if (node->cost_a < 0)
		neg_a = -1;
	if (node->cost_b < 0)
		neg_b = -1;
	total = (node->cost_a * neg_a) + (node->cost_b * neg_b);
	return (total);
}

t_stack	*cheapest_node(t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*cheapest;

	current = stack_b;
	cheapest = stack_b;
	while (current != NULL)
	{
		if (cost(current) < cost(cheapest))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	sorting_rotation(t_stack **stack_a)
{
	while (1)
	{
		if (min_index(*stack_a)->pos <= stack_size(*stack_a) / 2)
			rotate_stack(stack_a, "ra");
		else
			reverse_rotate_stack(stack_a, "rra");
		assign_pos(*stack_a);
		if (min_index(*stack_a)->pos == 0
			&& max_index(*stack_a)->pos != stack_size(*stack_a) - 1)
			ft_printf("Error in sorting rotation\n");
		if (min_index(*stack_a)->pos == 0)
			break ;
	}
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
