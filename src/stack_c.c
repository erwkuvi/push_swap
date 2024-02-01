/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:07:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 12:49:02 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	*create_stack_c(t_stack *stack)
{
	int		i;
	t_stack	*current;
	int		*arr;

	i = 0;
	current = stack;
	arr = malloc(sizeof(int) * stack_size(stack));
	if (!arr)
		return (NULL);
	while (current->next != NULL)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	arr[i] = current->value;
	return (arr);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[end];
	i = start - 1 ;
	j = start;
	while (j <= end -1)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void	ft_quicksort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		ft_quicksort(array, start, pivot_index - 1);
		ft_quicksort(array, pivot_index + 1, end);
	}
}

// void	ft_stack_c_new(t_stack *stack, int count)
// {
// 	int	*stack_c;
// 	int	i;

// 	stack_c = create_stack_c(stack);
// 	ft_quicksort(stack_c, 0, count - 1);
// 	assign_index_new(stack, stack_c, count);
// 	i = 0;
// 	while (i < count)
// 	{
// 		ft_printf("array int %d: %d\n", i, stack_c[i]);
// 		i++;
// 	}
// 	free(stack_c);
// }

void	ft_stack_c_new(t_stack *stack, int count)
{
	int	*stack_c;

	stack_c = create_stack_c(stack);
	ft_quicksort(stack_c, 0, count - 1);
	assign_index_new(stack, stack_c, count);
	free(stack_c);
}
