/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:06:44 by ekuchel           #+#    #+#             */
/*   Updated: 2024/02/01 16:05:14 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

// void	print_stuff(t_stack *stack_a, t_stack *stack_b)
// {
// 	ft_printf("Stack A\n");
// 	ft_printlist(stack_a, NULL);
// 	ft_printlist(stack_a, "index");
// 	ft_printlist(stack_a, "pos");
// 	ft_printf("Stack B\n");
// 	ft_printlist(stack_b, NULL);
// 	ft_printlist(stack_b, "index");
// 	ft_printlist(stack_b, "pos");
// 	ft_printlist(stack_b, "target_pos");
// 	ft_printlist(stack_b, "cost_a");
// 	ft_printlist(stack_b, "cost_b");
// }

void	push_swap(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (cyclicalsorted_new(*stack_a))
		assign_pos(*stack_a);
	else
	{
		pb_all_sorted_new(stack_b, stack_a, count);
		sort3(stack_a);
		while (stack_size(*stack_b) > 0)
		{
			assign_target_pos_new(*stack_a, *stack_b, count);
			assign_cost(*stack_a, *stack_b);
			rotate_cheapest(stack_a, stack_b, cheapest_node(*stack_b));
			push_to_stack(stack_a, stack_b, "pa");
		}
	}
	sorting_rotation(stack_a);
	free_list(*stack_a);
	free_list(*stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;
	int		*argv_stack;

	stack_a = NULL;
	stack_b = NULL;
	count = count_len(argc, argv);
	if (count < 2)
		exit (0);
	argv_stack = arg2stack(argc, argv, count);
	check_sorted(count, argv_stack);
	create_stack_new(count, argv_stack, &stack_a);
	if (count == 2)
		sort2(&stack_a);
	else if (count == 3)
	{
		sort3(&stack_a);
		free_list(stack_a);
	}
	else
		push_swap(&stack_a, &stack_b, count);
	return (0);
}
