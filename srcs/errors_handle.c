/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:22:32 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/21 15:00:15 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

void	generic_error(t_stack **stack, char **av)
{
	free_av(av);
	free_stack(stack);
	printf("\033[1;31mERROR: Problem with input. Check the arguments.\n");
	exit (1);
}

bool	check_av(const char *input)
{
	if (!(*input == '+' || *input == '-'
			|| ft_isdigit((unsigned char)*input)))
		return (true);
	if ((*input == '+' || *input == '-')
		&& !ft_isdigit((unsigned char)input[1]))
		return (true);
	while (*++input)
	{
		if (!ft_isdigit((unsigned char)*input))
			return (true);
	}
	return (false);
}

bool	check_duplicate(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	free_av(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i])
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
}
