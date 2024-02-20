/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:13 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 13:29:38 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->next = *stack;
	first->prev = NULL;
	(*stack)->prev = first;
	*stack = first;
}

void	rra(t_stack **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}

void	rrr_special(t_stack **stack_a, t_stack **stack_b, t_stack *b_m, bool pt)
{
	while (*stack_b != b_m->target && *stack_a != b_m)
		if (pt)
			rrr(stack_a, stack_b, pt);
	update_index(*stack_a);
	update_index(*stack_b);
}
