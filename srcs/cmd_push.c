/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:22:15 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 13:23:15 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_element;

	if (*src == NULL)
		return ;
	push_element = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_element->prev = NULL;
	if (!*dst)
	{
		*dst = push_element;
		push_element->next = NULL;
	}
	else
	{
		push_element->next = *dst;
		push_element->next->prev = push_element;
		*dst = push_element;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	if (!stack_a)
		return ;
	push(stack_a, stack_b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	if (print)
		ft_printf("pb\n");
}
