/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:44 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/15 11:55:57 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_last_element(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_best_match(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->best_match)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_min(t_stack *stack)
{
	int		smallest;
	t_stack	*min_element;

	smallest = INT_MAX;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			min_element = stack;
		}
		stack = stack->next;
	}
	return (min_element);
}
