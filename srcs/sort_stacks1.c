/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:24 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 15:46:34 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_match;

	best_match = find_best_match(*stack_a);
	if (best_match->above_median && best_match->target->above_median)
		rr_special(stack_a, stack_b, best_match, true);
	else if (!(best_match->above_median) && !(best_match->target->above_median))
		rrr_special(stack_a, stack_b, best_match, true);
	rotate_to_top(stack_a, best_match, 'a');
	rotate_to_top(stack_b, best_match->target, 'b');
	pb(stack_b, stack_a, true);
	update_index(*stack_a);
	update_index(*stack_b);
}

void	sort_b(t_stack **stack_a, t_stack **stack_b)
{
	update_index(*stack_a);
	update_index(*stack_b);
	update_target_b(*stack_a, *stack_b);
	rotate_to_top(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, true);
}

void	rotate_to_top(t_stack **stack_a, t_stack *top, char stack)
{
	while (*stack_a != top)
	{
		if (stack == 'a')
		{
			if (top->above_median)
				ra(stack_a, true);
			else
				rra(stack_a, true);
		}
		else if (stack == 'b')
		{
			if (top->above_median)
				rb(stack_a, true);
			else
				rrb(stack_a, true);
		}
	}
}

void	finish_sorting(t_stack **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		if (find_min(*stack_a)->above_median)
		{
			ra(stack_a, true);
		}
		else
		{
			rra(stack_a, true);
		}
	}
}
