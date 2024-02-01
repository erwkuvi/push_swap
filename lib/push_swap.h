/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:12:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/07/06 17:23:10 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include "./libftprintf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* utils.c / utils2.c /utils3.c / utils4.c / utils5.c */
// int		digit_compare(char **argv, int index, int value);
void	digit_compare_new(int *argv_stack, int index, int value);
void	printmove(char *str);
void	free_list(t_stack *head);
void	free_char_array(char **array);
// void	ft_printlist(t_stack *head, char *property);
void	ft_addnode(t_stack **head, int value);
void	ft_add_first(t_stack **head, int value);
void	print_error(void);
long	ft_atoil(const char *str);
// void	create_stack(int argc, char **argv, t_stack **stack);
void	create_stack_new(int count, int *argv_stack, t_stack **stack);
int		stack_size(t_stack *stack);
void	assign_pos(t_stack *stack);
// void	assign_index(t_stack *stack, int *array, int argc);
void	assign_index_new(t_stack *stack, int *array, int count);
// void	pb_all_sorted(t_stack **stack_b, t_stack **stack_a, int argc);
void	pb_all_sorted_new(t_stack **stack_b, t_stack **stack_a, int count);
// void	assign_target_pos(t_stack *stack_a, t_stack *stack_b, int argc);
void	assign_target_pos_new(t_stack *stack_a, t_stack *stack_b, int count);
void	assign_cost(t_stack *stack_a, t_stack *stack_b);
int		cost(t_stack *node);
int		ft_strcmp(char *s1, char *s2);
int		smallest_val(t_stack *b, char *pos_or_neg);
t_stack	*cheapest_node(t_stack *stack_b);
t_stack	*max_index(t_stack *stack);
t_stack	*min_index(t_stack *stack);
void	sorting_rotation(t_stack **stack_a);

/* execution.c*/
void	rotate_cheapest(t_stack	**stack_a, t_stack **stack_b, t_stack *cheap);
int		smallest_val(t_stack *b, char *pos_or_neg);

/*stack_c.c*/
// void	ft_stack_c(t_stack *stack, int argc);
void	ft_stack_c_new(t_stack *stack, int count);
int		*create_stack_c(t_stack *stack);
void	ft_quicksort(int *array, int start, int end);

/* checkers.c */
// void	check_digits_duplicates(int argc, char **argv);
// void	check_max_min(int argc, char **argv);
void	check_max_min_new(long value);
// int		check_arguments(int argc, char **argv);
void	check_sorted(int count, int *argv_stack);
// int		cyclicalsorted(int argc, char **argv);
int		cyclicalsorted_new(t_stack *stack_a);
int		count_len(int argc, char **argv);
int		*arg2stack(int argc, char **argv, int count);

/* operations.c */
void	swap_stack(t_stack **stack, char *move);
void	swap_both(t_stack **stack1, t_stack **stack2);
void	push_to_stack(t_stack **des_stack, t_stack **src_stack, char *move);
void	rotate_stack(t_stack **stack, char *move);
void	rotate_both(t_stack **stack1, t_stack **stack2);
void	reverse_rotate_stack(t_stack **stack, char *move);
void	reverse_rotate_both(t_stack **stack1, t_stack **stack2);

/*Algorithms - operations2.c*/
void	sort3(t_stack **stack);
void	sort2(t_stack **stack);

#endif
