/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:46:29 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 17:22:31 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	printmove(char *str)
{
	ft_putendl_fd(str, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

// void	ft_printlist(t_stack *head, char *property)
// {
// 	t_stack	*current;

// 	// if (!head)
// 	// {
// 	// 	print_error("print list / list empty");
// 	// 	return ;
// 	// }
// 	current = head;
// 	if (!property)
// 	{
// 		while (current != NULL)
// 		{
// 			ft_printf("%d ", current->value);
// 			current = current->next;
// 		}
// 	}
// 	if (!ft_strcmp(property, "pos"))
// 	{
// 		while (current != NULL)
// 		{
// 			ft_printf("position: %d\t", current->pos);
// 			current = current->next;
// 		}
// 	}
// 	else if (!ft_strcmp(property, "index"))
// 	{
// 		while (current != NULL)
// 		{
// 			ft_printf("index: %d\t", current->index);
// 			current = current->next;
// 		}
// 	}
// 	else if (!ft_strcmp(property, "target_pos"))
// 	{
// 		while (current != NULL)
// 		{
// 			ft_printf("target_pos: %d\t", current->target_pos);
// 			current = current->next;
// 		}
// 	}
// 	else if (!ft_strcmp(property, "cost_a"))
// 	{
// 		while (current != NULL)
// 		{
// 			ft_printf("cost_a: %d\t", current->cost_a);
// 			current = current->next;
// 		}
// 	}
// 	else if (!ft_strcmp(property, "cost_b"))
// 	{
// 		while (current != NULL)
// 		{
// 			ft_printf("cost_b: %d\t", current->cost_b);
// 			current = current->next;
// 		}
// 	}
// 	ft_printf("\n");
// }

void	free_list(t_stack *head)
{
	t_stack	*tmp;

	if (head)
	{
		while (head)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
	else
		return ;
}

void	ft_addnode(t_stack **head, int value)
{
	t_stack	*current;

	if (*head == NULL)
	{
		ft_add_first(head, value);
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = (t_stack *)malloc(sizeof(t_stack));
	current->next->value = value;
	current->next->next = NULL;
}
