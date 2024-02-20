/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:42 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 13:31:29 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **stack_a, bool print)
{
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second = (*stack_a)->next;
	(*stack_a)->next = second->next;
	second->prev = NULL;
	second->next = *stack_a;
	(*stack_a)->prev = second;
	*stack_a = second;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, bool print)
{
	t_stack	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	second = (*stack_b)->next;
	(*stack_b)->next = second->next;
	second->prev = NULL;
	second->next = *stack_b;
	(*stack_b)->prev = second;
	*stack_b = second;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	sa(stack_a, print);
	sb(stack_b, print);
	if (print)
		ft_printf("ss\n");
}
