/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:23:47 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/15 12:00:13 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	int		biggest;
	t_stack	*max_element;

	biggest = INT_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			max_element = stack;
		}
		stack = stack->next;
	}
	return (max_element);
}

int	find_min_value(t_stack *stack)
{
	int	smallest;

	if (!stack)
		return (1);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
		}
		stack = stack->next;
	}
	return (smallest);
}

int	find_max_value(t_stack *stack)
{
	int	largest;

	if (!stack)
		return (1);
	largest = INT_MIN;
	while (stack)
	{
		if (stack->value > largest)
		{
			largest = stack->value;
		}
		stack = stack->next;
	}
	return (largest);
}
