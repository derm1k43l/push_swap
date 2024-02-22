/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:03:07 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/22 16:40:51 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	parse_av(t_stack **stack_a, t_stack **stack_b,
	char *command, char **split_av)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		sa(stack_a, false);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		sb(stack_b, false);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(stack_b, stack_a, false);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ra(stack_a, false);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rb(stack_b, false);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		rra(stack_a, false);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(stack_b, false);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, false);
	else
		error_av(stack_a, stack_b, split_av, command);
}

void	error_av(t_stack **stack_a, t_stack **stack_b, char **split_av, char *command)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_av(split_av);
	free(command);
	printf("\033[1;31mERROR: Problem with input. Check the arguments.\n");
	exit(1);
}

void	process_commands(t_stack **stack_a, t_stack **stack_b, char **split_av)
{
	char	*commands;

	while (69)
	{
		commands = get_next_line(STDIN_FILENO);
		if (!commands)
			break ;
		parse_av(stack_a, stack_b, commands, split_av);
		free(commands);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_av;

	stack_a = NULL;
	stack_b = NULL;
	split_av = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
		split_av = ft_split2(av[1], 32);
	create_stack(&stack_a, split_av);
	process_commands(&stack_a, &stack_b, split_av);
	if (stack_sorted(stack_a) && !stack_b)
		ft_printf("\x1B[32mOK\x1B[0m\n");
	else
		ft_printf("\x1B[31mKO\x1B[0m\n");
	free_stack(&stack_a);
	free_av(split_av);
	return (0);
}
