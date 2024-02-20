/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:04:18 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/17 15:04:02 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	update_index(t_stack *stack)
{
	int		size;
	int		median;
	int		i;

	size = stack_size(stack);
	median = size / 2;
	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack->above_median = (i <= median);
		stack = stack->next;
		i++;
	}
}

void	update_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_element;
	int		best_match_value;

	while (stack_a)
	{
		best_match_value = INT_MIN;
		current_b = stack_b;
		target_element = NULL;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_value)
			{
				best_match_value = current_b->value;
				target_element = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_value == INT_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target_element;
		stack_a = stack_a->next;
	}
}

void	update_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_element;
	int		best_match_value;

	while (stack_b)
	{
		best_match_value = INT_MAX;
		current_a = stack_a;
		target_element = NULL;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_element = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == INT_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target_element;
		stack_b = stack_b->next;
	}
}

void	update_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = size_a - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += size_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	update_best_match(t_stack *stack)
{
	int		best_match_value;
	t_stack	*best_match;

	best_match_value = INT_MAX;
	best_match = stack;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->push_cost < best_match_value)
		{
			best_match_value = stack->push_cost;
			best_match = stack;
		}
		stack = stack->next;
	}
	best_match->best_match = true;
}
