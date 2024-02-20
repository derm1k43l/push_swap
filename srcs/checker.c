/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:03:07 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 15:46:00 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

void	parse_av(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(stack_b, stack_a, false);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
		error_av(stack_a, stack_b);
}

void	print_stack(t_stack *stack, const char *stack_name)
{
	ft_printf("%s: ", stack_name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	error_av(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	printf("\033[1;31mERROR: Problem with input. Check the arguments.\n");
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*commands;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		av = ft_split2(av[1], 32);
	create_stack(&stack_a, av);
	while (69)
	{
		commands = get_next_line(STDIN_FILENO);
		if (!commands)
			break ;
		parse_av(&stack_a, &stack_b, commands);
		free(commands);
	}
	if (stack_sorted(stack_a) && !stack_b)
		ft_printf("\x1B[32mOK\x1B[0m\n");
	else
		ft_printf("\x1B[31mKO\x1B[0m\n");
	free_stack(&stack_a);
	return (0);
}
