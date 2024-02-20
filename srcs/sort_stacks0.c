/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:22:25 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 13:32:37 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size >= 4)
		sort_special(stack_a, stack_b);
}

void	sort_two(t_stack **stack_a)
{
	t_stack	*top_element;

	top_element = *stack_a;
	if (top_element->value > top_element->next->value)
		sa(stack_a, true);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && c > a)
		sa(stack_a, true);
	else if (a > b && b > c && c < a)
	{
		sa(stack_a, true);
		rra(stack_a, true);
	}
	else if (a > b && b < c && c < a)
		ra(stack_a, true);
	else if (a < b && b > c && c > a)
	{
		sa(stack_a, true);
		ra(stack_a, true);
	}
	else if (a < b && b > c && c < a)
		rra(stack_a, true);
}

void	sort_special(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	if (size_a > 3 && !stack_sorted(*stack_a))
	{
		pb(stack_b, stack_a, true);
		size_a--;
	}
	while (size_a > 3 && !stack_sorted(*stack_a))
	{
		update_status_stack_a(*stack_a, *stack_b);
		sort_a(stack_a, stack_b);
		size_a = stack_size(*stack_a);
	}
	if (size_a == 3 && !stack_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
		sort_b(stack_a, stack_b);
	update_index(*stack_a);
	finish_sorting(stack_a);
}
